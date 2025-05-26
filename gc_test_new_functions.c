#include "./garbage_collector/inc/garbage_collector.h"
#include <assert.h>

// Test structure for generic function tests
typedef struct s_test_person
{
    char	*name;
    int		age;
    float	height;
}	t_test_person;

// Binary tree node structure
typedef struct s_test_btree
{
    int					value;
    struct s_test_btree	*left;
    struct s_test_btree	*right;
}	t_test_btree;

// Complex structure with multiple pointers
typedef struct s_test_complex
{
    void	*data;
    char	**strings;
    int		**matrix;
    int		value;
}	t_test_complex;

// Function for testing lstmap
void	*uppercase_first_char(t_gc *gc, void *content)
{
    char	*str;
    char	*result;

    str = (char *)content;
    if (!str || !*str)
        return (NULL);
    
    result = gc_strdup(gc, str);
    if (!result)
        return (NULL);
    
    if (result[0] >= 'a' && result[0] <= 'z')
        result[0] = result[0] - 'a' + 'A';
    
    return (result);
}

// Deletion function for lstmap
void	delete_string(void *content)
{
    if (content)
        free(content);
}

// Print functions for different tests
void	print_result(const char *test_name, int success)
{
    printf("%-40s %s\n", test_name, success ? "✅ PASS" : "❌ FAIL");
}

void	print_section_header(const char *section_name)
{
    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  %s\n", section_name);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

// Test functions
void	test_generic_functions(t_gc *gc)
{
    print_section_header("GENERIC STRUCTURE FUNCTIONS");
    
    // Test single struct allocation
    t_test_person *person = gc_alloc_struct(gc, sizeof(t_test_person));
    person->name = gc_strdup(gc, "John Doe");
    person->age = 30;
    person->height = 1.85f;
    
    print_result("gc_alloc_struct", person && person->name && 
                 !ft_strncmp(person->name, "John Doe", 8) && 
                 person->age == 30 && 
                 person->height == 1.85f);
    
    // Test struct duplication
    t_test_person *copy = gc_duplicate_struct(gc, person, sizeof(t_test_person));
    // String is not duplicated in shallow copy
    print_result("gc_duplicate_struct (shallow copy)", copy && 
                 copy->name == person->name &&
                 copy->age == person->age && 
                 copy->height == person->height);
    
    // Test full (deep) copy
    t_test_person *deep_copy = gc_duplicate_struct(gc, person, sizeof(t_test_person));
    deep_copy->name = gc_strdup(gc, person->name);
    print_result("gc_duplicate_struct (deep copy)", deep_copy && 
                 deep_copy->name && deep_copy->name != person->name &&
                 !ft_strncmp(deep_copy->name, person->name, ft_strlen(person->name)) &&
                 deep_copy->age == person->age && 
                 deep_copy->height == person->height);
    
    // Test struct array
    t_test_person *people = gc_alloc_struct_array(gc, 5, sizeof(t_test_person));
    int struct_array_valid = 1;
    for (int i = 0; i < 5; i++)
    {
        people[i].name = gc_strdup(gc, "Person");
        people[i].age = 20 + i;
        struct_array_valid &= (people[i].name != NULL);
    }
    print_result("gc_alloc_struct_array", people && struct_array_valid);
    
    // Test binary tree structure
    t_test_btree *root = gc_alloc_struct(gc, sizeof(t_test_btree));
    root->value = 10;
    root->left = gc_alloc_struct(gc, sizeof(t_test_btree));
    root->left->value = 5;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = gc_alloc_struct(gc, sizeof(t_test_btree));
    root->right->value = 15;
    root->right->left = NULL;
    root->right->right = NULL;
    
    print_result("Binary tree creation", root && root->left && root->right &&
                 root->value == 10 && root->left->value == 5 && 
                 root->right->value == 15);
    
    // Test binary tree subtree duplication
    t_test_btree *subtree = gc_duplicate_struct(gc, root->left, sizeof(t_test_btree));
    print_result("Binary subtree duplication", subtree && subtree->value == 5 &&
                 subtree->left == NULL && subtree->right == NULL);
}

void	test_array_functions(t_gc *gc)
{
    print_section_header("ARRAY FUNCTIONS");
    
    // 1D Integer Arrays
    int *numbers = gc_int_array_create(gc, 5);
    int array_valid = (numbers != NULL);
    for (int i = 0; i < 5; i++)
    {
        numbers[i] = i * 10;
        array_valid &= (numbers[i] == i * 10);
    }
    print_result("gc_int_array_create", array_valid);
    
    // Duplicate integer array
    int *numbers_dup = gc_int_array_dup(gc, numbers, 5);
    int dup_valid = (numbers_dup != NULL && numbers_dup != numbers);
    for (int i = 0; i < 5; i++)
        dup_valid &= (numbers_dup[i] == numbers[i]);
    print_result("gc_int_array_dup", dup_valid);
    
    // String arrays
    char **strings = gc_str_array_create(gc, 3);
    strings[0] = gc_strdup(gc, "First");
    strings[1] = gc_strdup(gc, "Second");
    strings[2] = gc_strdup(gc, "Third");
    print_result("gc_str_array_create", strings && strings[0] && strings[1] && 
                 strings[2] && strings[3] == NULL);
    
    // Duplicate string array
    char **strings_dup = gc_str_array_dup(gc, strings);
    print_result("gc_str_array_dup", strings_dup && strings_dup != strings &&
                 !ft_strncmp(strings_dup[0], "First", 5) &&
                 !ft_strncmp(strings_dup[1], "Second", 6) &&
                 !ft_strncmp(strings_dup[2], "Third", 5) &&
                 strings_dup[3] == NULL);
    
    // 2D Integer Arrays (Matrix)
    int **matrix = gc_int_matrix_create(gc, 3, 4);
    int matrix_valid = (matrix != NULL);
    for (int i = 0; i < 3; i++)
    {
        matrix_valid &= (matrix[i] != NULL);
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = i * 10 + j;
            matrix_valid &= (matrix[i][j] == i * 10 + j);
        }
    }
    print_result("gc_int_matrix_create", matrix_valid);
    
    // 3D Integer Arrays
    int ***cube = gc_int_3d_create(gc, 2, 2, 2);
    int cube_valid = (cube != NULL);
    for (int i = 0; i < 2; i++)
    {
        cube_valid &= (cube[i] != NULL);
        for (int j = 0; j < 2; j++)
        {
            cube_valid &= (cube[i][j] != NULL);
            for (int k = 0; k < 2; k++)
            {
                cube[i][j][k] = i * 100 + j * 10 + k;
                cube_valid &= (cube[i][j][k] == i * 100 + j * 10 + k);
            }
        }
    }
    print_result("gc_int_3d_create", cube_valid);
    
    // 3D String Arrays
    char ***str_cube = gc_str_3d_create(gc, 2, 2, 2);
    int str_cube_valid = (str_cube != NULL);
    for (int i = 0; i < 2; i++)
    {
        str_cube_valid &= (str_cube[i] != NULL);
        for (int j = 0; j < 2; j++)
        {
            str_cube_valid &= (str_cube[i][j] != NULL);
            char temp[50];
            for (int k = 0; k < 2; k++)
            {
                snprintf(temp, 50, "String-%d-%d-%d", i, j, k);
                // Cast to char** to properly access the string pointers
                ((char **)str_cube[i][j])[k] = gc_strdup(gc, temp);
                str_cube_valid &= (((char **)str_cube[i][j])[k] != NULL);
            }
        }
    }
    print_result("gc_str_3d_create", str_cube_valid);
}

void	test_list_functions(t_gc *gc)
{
    print_section_header("LIST FUNCTIONS");
    
    // Create a single node
    t_list *node = gc_lstnew(gc, gc_strdup(gc, "Test Node"));
    print_result("gc_lstnew", node && !ft_strncmp(node->content, "Test Node", 9));
    
    // Build list with gc_lstadd_back
    t_list *list = NULL;
    gc_lstadd_back(gc, &list, gc_strdup(gc, "first"));
    gc_lstadd_back(gc, &list, gc_strdup(gc, "second"));
    gc_lstadd_back(gc, &list, gc_strdup(gc, "third"));
    
    int list_valid = (list != NULL && 
                      !ft_strncmp(list->content, "first", 5) &&
                      !ft_strncmp(list->next->content, "second", 6) &&
                      !ft_strncmp(list->next->next->content, "third", 5) &&
                      list->next->next->next == NULL);
    print_result("gc_lstadd_back", list_valid);
    
    // Build list with gc_lstadd_front
    t_list *stack = NULL;
    gc_lstadd_front(gc, &stack, gc_strdup(gc, "third"));
    gc_lstadd_front(gc, &stack, gc_strdup(gc, "second"));
    gc_lstadd_front(gc, &stack, gc_strdup(gc, "first"));
    
    int stack_valid = (stack != NULL && 
                       !ft_strncmp(stack->content, "first", 5) &&
                       !ft_strncmp(stack->next->content, "second", 6) &&
                       !ft_strncmp(stack->next->next->content, "third", 5) &&
                       stack->next->next->next == NULL);
    print_result("gc_lstadd_front", stack_valid);
    
    // Test list duplication
    t_list *list_dup = gc_lstdup(gc, list);
    int dup_valid = (list_dup != NULL && list_dup != list);
    t_list *orig = list;
    t_list *copy = list_dup;
    while (orig && copy)
    {
        dup_valid &= (!ft_strncmp(orig->content, copy->content, 
                    ft_strlen(orig->content)));
        orig = orig->next;
        copy = copy->next;
    }
    dup_valid &= (orig == NULL && copy == NULL);
    print_result("gc_lstdup", dup_valid);
    
    // Test list from array
    char *items[] = {"apple", "banana", "cherry", NULL};
    t_list *fruit_list = gc_lst_from_array(gc, (void **)items);
    int array_list_valid = (fruit_list != NULL &&
                            !ft_strncmp(fruit_list->content, "apple", 5) &&
                            !ft_strncmp(fruit_list->next->content, "banana", 6) &&
                            !ft_strncmp(fruit_list->next->next->content, "cherry", 6) &&
                            fruit_list->next->next->next == NULL);
    print_result("gc_lst_from_array", array_list_valid);
    
    // Test sublist
    t_list *sublist = gc_lstsub(gc, fruit_list, 1, 2);
    int sublist_valid = (sublist != NULL &&
                         !ft_strncmp(sublist->content, "banana", 6) &&
                         !ft_strncmp(sublist->next->content, "cherry", 6) &&
                         sublist->next->next == NULL);
    print_result("gc_lstsub", sublist_valid);
    
    // Test list mapping
    t_list *strings_list = NULL;
    gc_lstadd_back(gc, &strings_list, gc_strdup(gc, "apple"));
    gc_lstadd_back(gc, &strings_list, gc_strdup(gc, "banana"));
    gc_lstadd_back(gc, &strings_list, gc_strdup(gc, "cherry"));
    
    t_list *uppercase_list = gc_lstmap(gc, strings_list, uppercase_first_char, delete_string);
    int map_valid = (uppercase_list != NULL &&
                     !ft_strncmp(uppercase_list->content, "Apple", 5) &&
                     !ft_strncmp(uppercase_list->next->content, "Banana", 6) &&
                     !ft_strncmp(uppercase_list->next->next->content, "Cherry", 6) &&
                     uppercase_list->next->next->next == NULL);
    print_result("gc_lstmap", map_valid);
}

void	test_complex_scenarios(t_gc *gc)
{
    print_section_header("COMPLEX SCENARIOS");
    
    // Complex structure with nested allocations
    t_test_complex *complex = gc_alloc_struct(gc, sizeof(t_test_complex));
    
    // Allocate void* data
    complex->data = gc_malloc(gc, 100);
    ft_memset(complex->data, 'A', 100);
    
    // Allocate string array
    complex->strings = gc_str_array_create(gc, 3);
    complex->strings[0] = gc_strdup(gc, "First string");
    complex->strings[1] = gc_strdup(gc, "Second string");
    complex->strings[2] = gc_strdup(gc, "Third string");
    
    // Allocate 2D matrix
    complex->matrix = gc_int_matrix_create(gc, 2, 3);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            complex->matrix[i][j] = i * 10 + j;
    
    complex->value = 42;
    
    // Validate the complex structure
    int complex_valid = (complex && complex->data && complex->strings && complex->matrix &&
                         ((char *)complex->data)[0] == 'A' &&
                         !ft_strncmp(complex->strings[0], "First string", 12) &&
                         !ft_strncmp(complex->strings[1], "Second string", 13) &&
                         !ft_strncmp(complex->strings[2], "Third string", 12) &&
                         complex->matrix[0][0] == 0 &&
                         complex->matrix[1][2] == 12 &&
                         complex->value == 42);
    print_result("Complex structure with nested allocations", complex_valid);
    
    // Create a linked list of complex structures
    t_list *complex_list = NULL;
    for (int i = 0; i < 3; i++)
    {
        t_test_complex *item = gc_alloc_struct(gc, sizeof(t_test_complex));
        item->data = gc_malloc(gc, 10);
        ft_memset(item->data, 'A' + i, 10);
        
        item->strings = gc_str_array_create(gc, 2);
        char temp[50];
        snprintf(temp, 50, "Item %d - String 1", i);
        item->strings[0] = gc_strdup(gc, temp);
        snprintf(temp, 50, "Item %d - String 2", i);
        item->strings[1] = gc_strdup(gc, temp);
        
        item->matrix = gc_int_matrix_create(gc, 2, 2);
        item->matrix[0][0] = i * 100;
        item->matrix[0][1] = i * 100 + 1;
        item->matrix[1][0] = i * 100 + 2;
        item->matrix[1][1] = i * 100 + 3;
        
        item->value = i * 10;
        
        gc_lstadd_back(gc, &complex_list, item);
    }
    
    // Validate complex list
    int complex_list_valid = (complex_list != NULL);
    t_list *current = complex_list;
    for (int i = 0; i < 3 && current; i++)
    {
        t_test_complex *item = (t_test_complex *)current->content;
        complex_list_valid &= (item && item->data && item->strings && item->matrix);
        complex_list_valid &= (((char *)item->data)[0] == 'A' + i);
        
        char temp[50];
        snprintf(temp, 50, "Item %d - String 1", i);
        complex_list_valid &= (!ft_strncmp(item->strings[0], temp, ft_strlen(temp)));
        
        complex_list_valid &= (item->matrix[0][0] == i * 100);
        complex_list_valid &= (item->value == i * 10);
        
        current = current->next;
    }
    complex_list_valid &= (current == NULL);
    
    print_result("Linked list of complex structures", complex_list_valid);
    
    // Test memory management by checking if everything is tracked
    size_t total_memory = gc_get_total_memory(gc);
    print_result("Memory tracking", total_memory > 0);
    printf("Total memory tracked: %zu bytes\n", total_memory);
}

int	main(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  GARBAGE COLLECTOR - NEW FUNCTIONS TEST\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    t_gc *gc = gc_create();
    if (!gc)
    {
        printf("Failed to create garbage collector\n");
        return (1);
    }

    // Run all test sections
    test_generic_functions(gc);
    test_array_functions(gc);
    test_list_functions(gc);
    test_complex_scenarios(gc);

    // Clean up everything
    printf("\nCleaning up all allocations...\n");
    gc_cleanup(&gc);
    printf("Cleanup complete. If no segfaults occurred, all memory was correctly tracked.\n");

    return (0);
}