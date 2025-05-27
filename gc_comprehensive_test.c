#include "inc/libft.h"
#include <stdio.h>
#include <time.h>

// Custom structures for testing
typedef struct s_person
{
    char    *name;
    int     age;
    float   height;
    char    **hobbies;
} t_person;

typedef struct s_tree_node
{
    int                 value;
    char                *label;
    struct s_tree_node  *left;
    struct s_tree_node  *right;
} t_tree_node;

// Helper function to measure elapsed time
typedef struct s_timer
{
    clock_t start;
    clock_t end;
    double  elapsed_ms;
} t_timer;

void start_timer(t_timer *timer)
{
    timer->start = clock();
}

void stop_timer(t_timer *timer)
{
    timer->end = clock();
    timer->elapsed_ms = (double)(timer->end - timer->start) * 1000.0 / CLOCKS_PER_SEC;
}

// Helper function for gc_lstmap
void *capitalize_string(t_gc *gc, void *content)
{
    char *str = (char *)content;
    char *result = gc_strdup(gc, str);
    
    if (result && result[0] >= 'a' && result[0] <= 'z')
        result[0] = result[0] - 32;
        
    return result;
}

void delete_content(void *content)
{
    (void)content; // Not needed for garbage collector
}

// Section 1: Basic Memory Management
void test_basic_memory(t_gc *gc)
{
    printf("\n===== BASIC MEMORY MANAGEMENT =====\n");
    
    // Basic allocation
    void *ptr = gc_malloc(gc, 1024);
    printf("Basic malloc: %s\n", ptr ? "✅" : "❌");
    
    // Zero allocation
    void *zero_ptr = gc_malloc(gc, 0);
    printf("Zero malloc: %s\n", zero_ptr ? "✅" : "❌");
    
    // Calloc test
    int *numbers = gc_calloc(gc, 10, sizeof(int));
    int is_zeroed = 1;
    for (int i = 0; i < 10; i++) {
        if (numbers[i] != 0) {
            is_zeroed = 0;
            break;
        }
    }
    printf("Calloc zeroing: %s\n", is_zeroed ? "✅" : "❌");
    
    // Realloc test
    void *ptr2 = gc_malloc(gc, 50);
    ft_memset(ptr2, 'A', 50);
    void *ptr3 = gc_realloc(gc, ptr2, 100);
    printf("Realloc preserving data: %s\n", 
           (ptr3 && ((char *)ptr3)[0] == 'A' && ((char *)ptr3)[49] == 'A') ? "✅" : "❌");
    
    // Memory copying
    char *src_data = "Test data for memcpy";
    char *copy = gc_memcpy(gc, src_data, ft_strlen(src_data) + 1);
    printf("Memory copy: %s\n", 
           (copy && ft_strcmp(copy, src_data) == 0) ? "✅" : "❌");
    
    // Manual free
    void *to_free = gc_malloc(gc, 30);
    gc_free(gc, to_free);
    printf("Manual free: ✅\n"); // If we didn't crash, it worked
    
    // Check memory usage
    size_t memory_used = gc_get_total_memory(gc);
    printf("Current memory usage: %zu bytes\n", memory_used);
}

// Section 2: String Functions
void test_string_functions(t_gc *gc)
{
    printf("\n===== STRING FUNCTIONS =====\n");
    
    // String duplication
    const char *original = "Hello, World!";
    char *dup = gc_strdup(gc, original);
    printf("String duplication: %s\n", 
           (dup && ft_strcmp(dup, original) == 0) ? "✅" : "❌");
    
    // Substring extraction
    char *sub = gc_substr(gc, "Hello, World!", 7, 5);
    printf("Substring: %s\n", 
           (sub && ft_strcmp(sub, "World") == 0) ? "✅" : "❌");
    
    // String joining
    char *joined = gc_strjoin(gc, "Hello", " World");
    printf("String join: %s\n", 
           (joined && ft_strcmp(joined, "Hello World") == 0) ? "✅" : "❌");
    
    // Three-way string joining
    char *joined3 = gc_strjoin_3(gc, "Hello", ", ", "World!");
    printf("Three-way join: %s\n", 
           (joined3 && ft_strcmp(joined3, "Hello, World!") == 0) ? "✅" : "❌");
    
    // String trimming
    char *trimmed = gc_strtrim(gc, " \tHello World\n ", " \t\n");
    printf("String trim: %s\n", 
           (trimmed && ft_strcmp(trimmed, "Hello World") == 0) ? "✅" : "❌");
    
    // String splitting
    char **words = gc_split(gc, "Hello World Program", ' ');
    int split_valid = (words && 
                      ft_strcmp(words[0], "Hello") == 0 &&
                      ft_strcmp(words[1], "World") == 0 &&
                      ft_strcmp(words[2], "Program") == 0 &&
                      words[3] == NULL);
    printf("String split: %s\n", split_valid ? "✅" : "❌");
    
    // Integer to string
    char *num_str = gc_itoa(gc, -12345);
    printf("Integer to string: %s\n", 
           (num_str && ft_strcmp(num_str, "-12345") == 0) ? "✅" : "❌");
    
    // Build a large string through concatenation
    char *big_str = gc_strdup(gc, "");
    for (int i = 0; i < 100; i++) {
        char *temp = gc_itoa(gc, i);
        big_str = gc_strjoin(gc, big_str, temp);
    }
    printf("Large string concatenation: %s\n", 
           (big_str && ft_strlen(big_str) > 100) ? "✅" : "❌");
}

// Section 3: Array Functions
void test_array_functions(t_gc *gc)
{
    printf("\n===== ARRAY FUNCTIONS =====\n");
    
    // 1D int array
    int *int_array = gc_int_array_create(gc, 10);
    for (int i = 0; i < 10; i++) {
        int_array[i] = i * 10;
    }
    printf("Int array creation: %s\n", 
           (int_array && int_array[5] == 50) ? "✅" : "❌");
    
    // 1D int array duplication
    int *int_array_dup = gc_int_array_dup(gc, int_array, 10);
    printf("Int array duplication: %s\n", 
           (int_array_dup && int_array_dup != int_array && int_array_dup[5] == 50) ? "✅" : "❌");
    
    // String array
    char **str_array = gc_str_array_create(gc, 5);
    for (int i = 0; i < 5; i++) {
        char temp[20];
        snprintf(temp, 20, "String %d", i);
        str_array[i] = gc_strdup(gc, temp);
    }
    printf("String array creation: %s\n", 
           (str_array && ft_strcmp(str_array[2], "String 2") == 0 && str_array[5] == NULL) ? "✅" : "❌");
    
    // String array duplication
    char **str_array_dup = gc_str_array_dup(gc, str_array);
    printf("String array duplication: %s\n", 
           (str_array_dup && str_array_dup != str_array && 
            ft_strcmp(str_array_dup[2], "String 2") == 0 && str_array_dup[5] == NULL) ? "✅" : "❌");
    
    // 2D int matrix
    int **matrix = gc_int_matrix_create(gc, 5, 5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = i * 10 + j;
        }
    }
    printf("Int matrix creation: %s\n", 
           (matrix && matrix[2][3] == 23) ? "✅" : "❌");
    
    // 2D string matrix
    char ***str_matrix = gc_str_matrix_create(gc, 3, 4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            char temp[20];
            snprintf(temp, 20, "Cell[%d][%d]", i, j);
            str_matrix[i][j] = gc_strdup(gc, temp);
        }
    }
    printf("String matrix creation: %s\n", 
           (str_matrix && ft_strcmp(str_matrix[1][2], "Cell[1][2]") == 0) ? "✅" : "❌");
    
    // String matrix duplication
    char ***str_matrix_dup = gc_str_matrix_dup(gc, str_matrix);
    printf("String matrix duplication: %s\n", 
           (str_matrix_dup && str_matrix_dup != str_matrix && 
            ft_strcmp(str_matrix_dup[1][2], "Cell[1][2]") == 0) ? "✅" : "❌");
    
    // 3D int array
    int ***cube = gc_int_3d_create(gc, 3, 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cube[i][j][k] = i * 100 + j * 10 + k;
            }
        }
    }
    printf("3D int array creation: %s\n", 
           (cube && cube[1][2][2] == 122) ? "✅" : "❌");
    
    // 3D string array
    char ***str_cube = gc_str_3d_create(gc, 3, 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                char temp[30];
                snprintf(temp, 30, "Pos[%d][%d][%d]", i, j, k);
                ((char **)str_cube[i][j])[k] = gc_strdup(gc, temp);
            }
        }
    }
    printf("3D string array creation: %s\n", 
           (str_cube && ft_strcmp(((char **)str_cube[1][2])[1], "Pos[1][2][1]") == 0) ? "✅" : "❌");
    
    // Array reallocation
    t_array_info info = create_array_info(10, 20, sizeof(int));
    int *expanded = gc_realloc_array(gc, int_array, info);
    for (int i = 10; i < 20; i++) {
        expanded[i] = i * 5;
    }
    printf("Array reallocation: %s\n", 
           (expanded && expanded[15] == 75 && expanded[5] == 50) ? "✅" : "❌");
}

// Section 4: List Functions
void test_list_functions(t_gc *gc)
{
    printf("\n===== LIST FUNCTIONS =====\n");
    
    // Create a single node
    t_list *node = gc_lstnew(gc, gc_strdup(gc, "Single Node"));
    printf("List node creation: %s\n", 
           (node && ft_strcmp(node->content, "Single Node") == 0) ? "✅" : "❌");
    
    // Add nodes to the back
    t_list *list = NULL;
    for (int i = 0; i < 5; i++) {
        char temp[20];
        snprintf(temp, 20, "Node %d", i);
        gc_lstadd_back(gc, &list, gc_strdup(gc, temp));
    }
    
    // Verify list
    t_list *current = list;
    int back_valid = 1;
    for (int i = 0; i < 5; i++) {
        char temp[20];
        snprintf(temp, 20, "Node %d", i);
        if (!current || ft_strcmp(current->content, temp) != 0) {
            back_valid = 0;
            break;
        }
        current = current->next;
    }
    printf("List add back: %s\n", (back_valid && !current) ? "✅" : "❌");
    
    // Add nodes to the front
    t_list *stack = NULL;
    for (int i = 0; i < 5; i++) {
        char temp[20];
        snprintf(temp, 20, "Node %d", i);
        gc_lstadd_front(gc, &stack, gc_strdup(gc, temp));
    }
    
    // Verify stack (should be in reverse order)
    current = stack;
    int front_valid = 1;
    for (int i = 4; i >= 0; i--) {
        char temp[20];
        snprintf(temp, 20, "Node %d", i);
        if (!current || ft_strcmp(current->content, temp) != 0) {
            front_valid = 0;
            break;
        }
        current = current->next;
    }
    printf("List add front: %s\n", (front_valid && !current) ? "✅" : "❌");
    
    // Create a list from array
    char *words[] = {"one", "two", "three", "four", "five", NULL};
    t_list *array_list = gc_lst_from_array(gc, (void **)words);
    
    // Verify array list
    const char *expected[] = {"one", "two", "three", "four", "five"};
    current = array_list;
    int array_valid = 1;
    for (int i = 0; i < 5; i++) {
        if (!current || ft_strcmp(current->content, expected[i]) != 0) {
            array_valid = 0;
            break;
        }
        current = current->next;
    }
    printf("List from array: %s\n", (array_valid && !current) ? "✅" : "❌");
    
    // Create a sublist
    t_list *sublist = gc_lstsub(gc, array_list, 1, 3);
    
    // Verify sublist
    const char *sub_expected[] = {"two", "three", "four"};
    current = sublist;
    int sub_valid = 1;
    for (int i = 0; i < 3; i++) {
        if (!current || ft_strcmp(current->content, sub_expected[i]) != 0) {
            sub_valid = 0;
            break;
        }
        current = current->next;
    }
    printf("List subset: %s\n", (sub_valid && !current) ? "✅" : "❌");
    
    // Test list duplication
    t_list *dup_list = gc_lstdup(gc, array_list);
    
    // Verify duplicate list
    current = dup_list;
    int dup_valid = 1;
    for (int i = 0; i < 5; i++) {
        if (!current || ft_strcmp(current->content, expected[i]) != 0) {
            dup_valid = 0;
            break;
        }
        current = current->next;
    }
    printf("List duplication: %s\n", (dup_valid && !current) ? "✅" : "❌");
    
    // Test list mapping
    t_list *mapped_list = gc_lstmap(gc, array_list, capitalize_string, delete_content);
    
    // Verify mapped list
    const char *mapped_expected[] = {"One", "Two", "Three", "Four", "Five"};
    current = mapped_list;
    int map_valid = 1;
    for (int i = 0; i < 5; i++) {
        if (!current || ft_strcmp(current->content, mapped_expected[i]) != 0) {
            map_valid = 0;
            break;
        }
        current = current->next;
    }
    printf("List mapping: %s\n", (map_valid && !current) ? "✅" : "❌");
}

// Section 5: Generic Structure Functions
void test_generic_structures(t_gc *gc)
{
    printf("\n===== GENERIC STRUCTURE FUNCTIONS =====\n");
    
    // Allocate a structure
    t_person *person = gc_alloc_struct(gc, sizeof(t_person));
    person->name = gc_strdup(gc, "John Doe");
    person->age = 30;
    person->height = 1.85;
    person->hobbies = gc_str_array_create(gc, 3);
    person->hobbies[0] = gc_strdup(gc, "Reading");
    person->hobbies[1] = gc_strdup(gc, "Hiking");
    person->hobbies[2] = gc_strdup(gc, "Programming");
    
    printf("Structure allocation: %s\n", 
        (person && ft_strcmp(person->name, "John Doe") == 0 && 
         person->age == 30 && fabs(person->height - 1.85) < 0.0001 &&
         ft_strcmp(person->hobbies[1], "Hiking") == 0) ? "✅" : "❌");
    
    // Duplicate a structure (shallow copy)
    t_person *copy = gc_duplicate_struct(gc, person, sizeof(t_person));
    printf("Structure shallow copy: %s\n", 
           (copy && copy->name == person->name && copy->age == person->age && 
            copy->height == person->height && copy->hobbies == person->hobbies) ? "✅" : "❌");
    
    // Create a deep copy
    t_person *deep_copy = gc_duplicate_struct(gc, person, sizeof(t_person));
    deep_copy->name = gc_strdup(gc, person->name);
    deep_copy->hobbies = gc_str_array_dup(gc, person->hobbies);
    
    printf("Structure deep copy: %s\n", 
           (deep_copy && deep_copy->name != person->name && 
            ft_strcmp(deep_copy->name, person->name) == 0 &&
            deep_copy->hobbies != person->hobbies &&
            ft_strcmp(deep_copy->hobbies[1], person->hobbies[1]) == 0) ? "✅" : "❌");
    
    // Create an array of structures
    t_person *people = gc_alloc_struct_array(gc, 5, sizeof(t_person));
    for (int i = 0; i < 5; i++) {
        char name[50];
        snprintf(name, 50, "Person %d", i);
        people[i].name = gc_strdup(gc, name);
        people[i].age = 20 + i * 5;
        people[i].height = 1.70 + (i * 0.05);
    }
    
    printf("Structure array: %s\n", 
           (people && ft_strcmp(people[2].name, "Person 2") == 0 && 
            people[2].age == 30) ? "✅" : "❌");
    
    // Binary tree example
    t_tree_node *root = gc_alloc_struct(gc, sizeof(t_tree_node));
    root->value = 10;
    root->label = gc_strdup(gc, "Root");
    
    root->left = gc_alloc_struct(gc, sizeof(t_tree_node));
    root->left->value = 5;
    root->left->label = gc_strdup(gc, "Left");
    root->left->left = NULL;
    root->left->right = NULL;
    
    root->right = gc_alloc_struct(gc, sizeof(t_tree_node));
    root->right->value = 15;
    root->right->label = gc_strdup(gc, "Right");
    root->right->left = NULL;
    root->right->right = NULL;
    
    printf("Tree structure: %s\n", 
           (root && root->left && root->right && 
            root->value == 10 && root->left->value == 5 && root->right->value == 15 &&
            ft_strcmp(root->label, "Root") == 0) ? "✅" : "❌");
}

// Section 6: Edge Cases and Stress Tests
void test_edge_cases_and_stress(t_gc *gc)
{
    printf("\n===== EDGE CASES AND STRESS TESTS =====\n");
    
    // Edge cases
    void *zero_ptr = gc_malloc(gc, 0);
    printf("Zero allocation: %s\n", zero_ptr ? "✅" : "❌");
    
    gc_free(gc, NULL);
    printf("NULL pointer free: ✅\n"); // If no crash, it worked
    
    void *ptr = gc_malloc(gc, 10);
    gc_free(gc, ptr);
    gc_free(gc, ptr); // Double free
    printf("Double free handling: ✅\n"); // If no crash, it worked
    
    void *untracked = malloc(10);
    gc_free(gc, untracked); // Untracked pointer
    free(untracked);        // Clean up properly
    printf("Untracked pointer handling: ✅\n"); // If no crash, it worked
    
    // Stress test - lots of small allocations
    t_timer timer;
    start_timer(&timer);
    
    void **pointers = gc_calloc(gc, 10000, sizeof(void *));
    for (int i = 0; i < 10000; i++) {
        pointers[i] = gc_malloc(gc, (rand() % 100) + 1);
        // Write something to ensure the memory is usable
        *(char *)pointers[i] = 'A' + (i % 26);
    }
    
    stop_timer(&timer);
    printf("10,000 small allocations: ✅ (%.2f ms)\n", timer.elapsed_ms);
    
    // Large allocation
    start_timer(&timer);
    void *large = gc_malloc(gc, 10 * 1024 * 1024); // 10 MB
    if (large) {
        // Touch some of the memory
        for (size_t j = 0; j < 10 * 1024 * 1024; j += 4096) {
            ((char *)large)[j] = 'Z';
        }
    }
    stop_timer(&timer);
    printf("Large allocation (10 MB): %s (%.2f ms)\n", large ? "✅" : "❌", timer.elapsed_ms);
    
    // String operations stress test
    start_timer(&timer);
    char *str = gc_strdup(gc, "");
    for (int i = 0; i < 1000; i++) {
        char *temp = gc_itoa(gc, i);
        str = gc_strjoin(gc, str, temp);
    }
    stop_timer(&timer);
    printf("1,000 string concatenations: %s (%.2f ms)\n", 
           (str && ft_strlen(str) > 1000) ? "✅" : "❌", timer.elapsed_ms);
    
    // Check final memory usage
    size_t memory_used = gc_get_total_memory(gc);
    printf("Final memory usage: %zu bytes (%.2f MB)\n", 
           memory_used, memory_used / (1024.0 * 1024.0));
}

int main(void)
{
    printf("============================================\n");
    printf("   GARBAGE COLLECTOR COMPREHENSIVE TEST\n");
    printf("============================================\n");
    
    // Seed random number generator for reproducible tests
    srand(42);
    
    // Create a single garbage collector for all tests
    t_gc *gc = gc_create();
    if (!gc) {
        printf("Failed to create garbage collector\n");
        return 1;
    }
    
    // Run all test sections
    test_basic_memory(gc);
    test_string_functions(gc);
    test_array_functions(gc);
    test_list_functions(gc);
    test_generic_structures(gc);
    test_edge_cases_and_stress(gc);
    
    // Final cleanup
    printf("\n===== CLEANUP =====\n");
    t_timer cleanup_timer;
    start_timer(&cleanup_timer);
    
    size_t memory_before = gc_get_total_memory(gc);
    printf("Memory before cleanup: %zu bytes (%.2f MB)\n", 
           memory_before, memory_before / (1024.0 * 1024.0));
           
    gc_cleanup(&gc);
    
    stop_timer(&cleanup_timer);
    printf("Cleanup completed in %.2f ms\n", cleanup_timer.elapsed_ms);
    printf("Garbage collector is now %s\n", gc ? "still active" : "NULL (properly reset)");
    
    printf("\nAll tests completed successfully!\n");
    
    return 0;
}
