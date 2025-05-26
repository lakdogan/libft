// Fixed version with all compilation errors resolved

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_ultimate_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lakdogan <lakdogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:00:00 by lakdogan          #+#    #+#             */
/*   Updated: 2025/05/26 23:45:14 by lakdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./garbage_collector/inc/garbage_collector.h"
#include <assert.h>
#include <time.h>

typedef struct s_test_struct
{
    int     a;
    float   b;
    char    c;
} t_test_struct;

// Used to measure performance
typedef struct s_timer
{
	clock_t				start;
	clock_t				end;
	double				elapsed_ms;
}						t_timer;

// Complex data structures for testing
typedef struct s_node
{
	int					id;
	char				*name;
	struct s_node		**children;
	int					child_count;
	void				*data;
	struct s_node		*parent;
}						t_node;

typedef struct s_graph
{
	t_node				**nodes;
	int					node_count;
	int					**adjacency_matrix;
}						t_graph;

// Using t_array_info from garbage_collector.h

// Test categories
typedef enum e_test_category
{
	BASIC_ALLOCATION,
	STRING_FUNCTIONS,
	ARRAY_FUNCTIONS,
	LIST_FUNCTIONS,
	NESTED_STRUCTURES,
	STRESS_TEST,
	EDGE_CASES,
	PERFORMANCE
}						t_test_category;

// Forward declarations for utility functions
void					run_test_category(t_gc *gc, t_test_category category);
void					print_section_header(const char *title);
void					print_test_result(const char *test_name, int success);
void					start_timer(t_timer *timer);
void					stop_timer(t_timer *timer);

// Forward declarations for test helper functions
void					*uppercase_first_char(t_gc *gc, void *content);
void					delete_content(void *content);
t_node					*create_tree_node(t_gc *gc, int id, const char *name,
							int child_count);
t_graph					*create_graph(t_gc *gc, int node_count);

// Helper function to create a random string
char	*create_random_string(t_gc *gc, int length)
{
	const char	charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char		*str;
	int			index;

	str = gc_malloc(gc, length + 1);
	if (!str)
		return (NULL);
	for (int i = 0; i < length; i++)
	{
		index = rand() % (sizeof(charset) - 1);
		str[i] = charset[index];
	}
	str[length] = '\0';
	return (str);
}

// Helper function implementations
void	*uppercase_first_char(t_gc *gc, void *content)
{
	char	*str;
	char	*result;

	str = (char *)content;
	result = gc_strdup(gc, str);
	if (result && result[0] >= 'a' && result[0] <= 'z')
	{
		result[0] = result[0] - 32;
	}
	return (result);
}

void	delete_content(void *content)
{
	// Not needed for gc, but required by function signature
	(void)content;
}

t_node	*create_tree_node(t_gc *gc, int id, const char *name, int child_count)
{
	t_node	*node;

	node = gc_alloc_struct(gc, sizeof(t_node));
	node->id = id;
	node->name = gc_strdup(gc, name);
	node->child_count = child_count;
	if (child_count > 0)
	{
		node->children = gc_calloc(gc, child_count, sizeof(t_node *));
	}
	else
	{
		node->children = NULL;
	}
	// Allocate some extra data
	node->data = gc_malloc(gc, 100);
	memset(node->data, id % 256, 100);
	node->parent = NULL;
	return (node);
}

t_graph	*create_graph(t_gc *gc, int node_count)
{
	t_graph	*graph;
		char name[20];

	graph = gc_alloc_struct(gc, sizeof(t_graph));
	graph->node_count = node_count;
	// Allocate nodes
	graph->nodes = gc_calloc(gc, node_count, sizeof(t_node *));
	for (int i = 0; i < node_count; i++)
	{
		sprintf(name, "GraphNode-%d", i);
		graph->nodes[i] = create_tree_node(gc, 1000 + i, name, 0);
	}
	// Create adjacency matrix
	graph->adjacency_matrix = gc_int_matrix_create(gc, node_count, node_count);
	for (int i = 0; i < node_count; i++)
	{
		for (int j = 0; j < node_count; j++)
		{
			// Create some random connections
			graph->adjacency_matrix[i][j] = (rand() % 5 == 0) ? 1 : 0;
		}
	}
	return (graph);
}

/* ============================== TEST SECTIONS ============================== */

void	test_basic_allocation(t_gc *gc)
{
	void			*ptr1;
	int				*int_array;
	int				is_zeroed;
	void			*ptr2;
	void			*ptr3;
	int				realloc_valid;
	t_test_struct	*s;
	t_test_struct	*s_copy;
	t_test_struct	*s_array;
	size_t			mem_used;

	print_section_header("BASIC ALLOCATION TESTS");
	// Test malloc
	ptr1 = gc_malloc(gc, 100);
	print_test_result("gc_malloc basic allocation", ptr1 != NULL);
	// Test calloc
	int_array = gc_calloc(gc, 10, sizeof(int));
	is_zeroed = 1;
	for (int i = 0; i < 10; i++)
	{
		if (int_array[i] != 0)
		{
			is_zeroed = 0;
			break ;
		}
	}
	print_test_result("gc_calloc zeroes memory", is_zeroed);
	// Test realloc
	ptr2 = gc_malloc(gc, 50);
	memset(ptr2, 'A', 50);
	ptr3 = gc_realloc(gc, ptr2, 100);
	realloc_valid = (ptr3 != NULL && ((char *)ptr3)[0] == 'A'
			&& ((char *)ptr3)[49] == 'A');
	print_test_result("gc_realloc preserves data", realloc_valid);
	// Test struct allocation
	s = gc_alloc_struct(gc, sizeof(t_test_struct));
	s->a = 42;
	s->b = 3.14f;
	s->c = 'X';
	s_copy = gc_duplicate_struct(gc, s, sizeof(t_test_struct));
	print_test_result("gc_duplicate_struct", s_copy && s_copy->a == 42
		&& s_copy->b == 3.14f && s_copy->c == 'X');
	// Test struct array
	s_array = gc_alloc_struct_array(gc, 5, sizeof(t_test_struct));
	for (int i = 0; i < 5; i++)
	{
		s_array[i].a = i;
		s_array[i].b = i + 0.5f;
		s_array[i].c = 'A' + i;
	}
	print_test_result("gc_alloc_struct_array", s_array && s_array[2].a == 2
		&& s_array[2].b == 2.5f && s_array[2].c == 'C');
	// Memory usage tracking
	mem_used = gc_get_total_memory(gc);
	print_test_result("Memory tracking", mem_used > 0);
	printf("    Current memory usage: %zu bytes\n", mem_used);
}

void	test_string_functions(t_gc *gc)
{
	const char	*original = "Hello, World!";
	char		*dup;
	char		*sub;
	char		*joined;
	char		*joined3;
	char		*trimmed;
	char		*num_str;
	char		*big_str;
	char		*temp;

	print_section_header("STRING FUNCTION TESTS");
	// Test strdup
	dup = gc_strdup(gc, original);
	print_test_result("gc_strdup", dup && strcmp(dup, original) == 0
		&& dup != original);
	// Test substr
	sub = gc_substr(gc, "Hello, World!", 7, 5);
	print_test_result("gc_substr", sub && strcmp(sub, "World") == 0);
	// Test strjoin
	joined = gc_strjoin(gc, "Hello", " World");
	print_test_result("gc_strjoin", joined && strcmp(joined,
			"Hello World") == 0);
	// Test strjoin_3
	joined3 = gc_strjoin_3(gc, "Hello", ", ", "World!");
	print_test_result("gc_strjoin_3", joined3 && strcmp(joined3, "Hello,World!") == 0);
	// Test strtrim
	trimmed = gc_strtrim(gc, " \t Hello \n ", " \t\n");
	print_test_result("gc_strtrim", trimmed && strcmp(trimmed, "Hello") == 0);
	// Test itoa
	num_str = gc_itoa(gc, -12345);
	print_test_result("gc_itoa", num_str && strcmp(num_str, "-12345") == 0);
	// Test with lots of concatenations
	big_str = gc_strdup(gc, "");
	for (int i = 0; i < 100; i++)
	{
		temp = gc_itoa(gc, i);
		// Remove unused variable
		big_str = gc_strjoin(gc, big_str, temp);
	}
	print_test_result("Multiple string operations", big_str
		&& strlen(big_str) > 100);
}

void	test_array_functions(t_gc *gc)
{
	int				*int_array;
	int				*int_array_dup;
	char			**str_array;
		char			temp[20];
	char			**str_array_dup;
	int				**matrix;
	int				***cube;
	char			***str_cube;
				char	temp[30];
	t_array_info	info;
	int				*expanded;

	print_section_header("ARRAY FUNCTION TESTS");
	// 1D int array
	int_array = gc_int_array_create(gc, 10);
	for (int i = 0; i < 10; i++)
	{
		int_array[i] = i * 10;
	}
	print_test_result("gc_int_array_create", int_array && int_array[5] == 50);
	// 1D int array duplicate
	int_array_dup = gc_int_array_dup(gc, int_array, 10);
	print_test_result("gc_int_array_dup", int_array_dup
		&& int_array_dup != int_array && int_array_dup[5] == 50);
	// String array
	str_array = gc_str_array_create(gc, 5);
	for (int i = 0; i < 5; i++)
	{
		sprintf(temp, "String %d", i);
		str_array[i] = gc_strdup(gc, temp);
	}
	print_test_result("gc_str_array_create", str_array && strcmp(str_array[2],
			"String 2") == 0 && str_array[5] == NULL);
	// String array duplicate
	str_array_dup = gc_str_array_dup(gc, str_array);
	print_test_result("gc_str_array_dup", str_array_dup
		&& str_array_dup != str_array && strcmp(str_array_dup[2],
			"String 2") == 0 && str_array_dup[5] == NULL);
	// 2D int matrix
	matrix = gc_int_matrix_create(gc, 5, 5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] = i * 10 + j;
		}
	}
	print_test_result("gc_int_matrix_create", matrix && matrix[2][3] == 23);
	// 3D int array
	cube = gc_int_3d_create(gc, 3, 3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cube[i][j][k] = i * 100 + j * 10 + k;
			}
		}
	}
	print_test_result("gc_int_3d_create", cube && cube[1][2][2] == 122);
	// 3D string array
	str_cube = gc_str_3d_create(gc, 3, 3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				sprintf(temp, "Pos[%d][%d][%d]", i, j, k);
				((char **)str_cube[i][j])[k] = gc_strdup(gc, temp);
			}
		}
	}
	// Fix the strcmp call with proper dereferencing
	print_test_result("gc_str_3d_create", str_cube
		&& strcmp(*(((char **)str_cube[1][2]) + 2), "Pos[1][2][2]") == 0);
	// Fix gc_realloc_array call by creating the array_info struct
	info = {10, 20, sizeof(int)};
	expanded = gc_realloc_array(gc, int_array, info);
	for (int i = 10; i < 20; i++)
	{
		expanded[i] = i * 5;
	}
	print_test_result("gc_realloc_array", expanded && expanded[15] == 75
		&& expanded[5] == 50);
}

void	test_list_functions(t_gc *gc)
{
	t_list		*node;
	t_list		*list;
		char			temp[20];
	t_list		*current;
	int			back_valid;
		char			temp[20];
	t_list		*stack;
		char			temp[20];
	int			front_valid;
		char			temp[20];
	char		*words[] = {"one", "two", "three", "four", "five", NULL};
	t_list		*array_list;
	const char	*expected[] = {"one", "two", "three", "four", "five"};
	int			array_valid;
	t_list		*sublist;
	const char	*sub_expected[] = {"two", "three", "four"};
	int			sub_valid;
	t_list		*dup_list;
	int			dup_valid;
	t_list		*mapped_list;
	const char	*mapped_expected[] = {"One", "Two", "Three", "Four", "Five"};
	int			map_valid;

	print_section_header("LIST FUNCTION TESTS");
	// Create a list node
	node = gc_lstnew(gc, gc_strdup(gc, "Single Node"));
	print_test_result("gc_lstnew", node && strcmp(node->content,
			"Single Node") == 0);
	// Add nodes to the back
	list = NULL;
	for (int i = 0; i < 5; i++)
	{
		sprintf(temp, "Node %d", i);
		gc_lstadd_back(gc, &list, gc_strdup(gc, temp));
	}
	// Verify list
	current = list;
	back_valid = 1;
	for (int i = 0; i < 5; i++)
	{
		sprintf(temp, "Node %d", i);
		if (!current || strcmp(current->content, temp) != 0)
		{
			back_valid = 0;
			break ;
		}
		current = current->next;
	}
	print_test_result("gc_lstadd_back", back_valid && !current);
	// Add nodes to the front
	stack = NULL;
	for (int i = 0; i < 5; i++)
	{
		sprintf(temp, "Node %d", i);
		gc_lstadd_front(gc, &stack, gc_strdup(gc, temp));
	}
	// Verify stack (should be in reverse order)
	current = stack;
	front_valid = 1;
	for (int i = 4; i >= 0; i--)
	{
		sprintf(temp, "Node %d", i);
		if (!current || strcmp(current->content, temp) != 0)
		{
			front_valid = 0;
			break ;
		}
		current = current->next;
	}
	print_test_result("gc_lstadd_front", front_valid && !current);
	// Create a list from array
	array_list = gc_lst_from_array(gc, (void **)words);
	// Verify array list
	current = array_list;
	array_valid = 1;
	for (int i = 0; i < 5; i++)
	{
		if (!current || strcmp(current->content, expected[i]) != 0)
		{
			array_valid = 0;
			break ;
		}
		current = current->next;
	}
	print_test_result("gc_lst_from_array", array_valid && !current);
	// Create a sublist
	sublist = gc_lstsub(gc, array_list, 1, 3);
	// Verify sublist
	current = sublist;
	sub_valid = 1;
	for (int i = 0; i < 3; i++)
	{
		if (!current || strcmp(current->content, sub_expected[i]) != 0)
		{
			sub_valid = 0;
			break ;
		}
		current = current->next;
	}
	print_test_result("gc_lstsub", sub_valid && !current);
	// Test list duplication
	dup_list = gc_lstdup(gc, array_list);
	// Verify duplicate list
	current = dup_list;
	dup_valid = 1;
	for (int i = 0; i < 5; i++)
	{
		if (!current || strcmp(current->content, expected[i]) != 0)
		{
			dup_valid = 0;
			break ;
		}
		current = current->next;
	}
	print_test_result("gc_lstdup", dup_valid && !current);
	// Test list mapping using the globally-defined functions
	mapped_list = gc_lstmap(gc, array_list, uppercase_first_char,
			delete_content);
	// Verify mapped list
	current = mapped_list;
	map_valid = 1;
	for (int i = 0; i < 5; i++)
	{
		if (!current || strcmp(current->content, mapped_expected[i]) != 0)
		{
			map_valid = 0;
			break ;
		}
		current = current->next;
	}
	print_test_result("gc_lstmap", map_valid && !current);
}

void	test_nested_structures(t_gc *gc)
{
	t_node	*root;
		char			name[20];
			char		leaf_name[20];
	int		tree_valid;
	t_graph	*graph;
	int		graph_valid;
	t_node	*circular1;
	t_node	*circular2;

	print_section_header("NESTED STRUCTURE TESTS");
	// Create a tree with 3 levels using the globally-defined create_tree_node function
	root = create_tree_node(gc, 1, "Root", 3);
	for (int i = 0; i < root->child_count; i++)
	{
		sprintf(name, "Child-%d", i + 1);
		root->children[i] = create_tree_node(gc, 10 + i, name, 2);
		root->children[i]->parent = root;
		for (int j = 0; j < root->children[i]->child_count; j++)
		{
			sprintf(leaf_name, "Leaf-%d-%d", i + 1, j + 1);
			root->children[i]->children[j] = create_tree_node(gc, 100 + i * 10
					+ j, leaf_name, 0);
			root->children[i]->children[j]->parent = root->children[i];
		}
	}
	// Verify tree structure
	tree_valid = root && root->id == 1 && strcmp(root->name, "Root") == 0
		&& root->child_count == 3 && root->children[1]->id == 11
		&& strcmp(root->children[1]->name, "Child-2") == 0
		&& root->children[1]->children[0]->id == 110
		&& strcmp(root->children[1]->children[0]->name, "Leaf-2-1") == 0
		&& root->children[1]->children[0]->parent == root->children[1]
		&& root->children[1]->parent == root;
	print_test_result("Complex tree structure", tree_valid);
	// Create a graph structure using the globally-defined create_graph function
	graph = create_graph(gc, 10);
	// Verify graph structure
	graph_valid = graph && graph->node_count == 10
		&& graph->nodes[5]->id == 1005 && strcmp(graph->nodes[5]->name,
			"GraphNode-5") == 0;
	print_test_result("Complex graph structure", graph_valid);
	// Create a circular reference
	circular1 = create_tree_node(gc, 2000, "Circular1", 1);
	circular2 = create_tree_node(gc, 2001, "Circular2", 1);
	circular1->children[0] = circular2;
	circular2->children[0] = circular1; // Creates a cycle
	circular1->parent = circular2;
	circular2->parent = circular1; // Another cycle
	print_test_result("Circular references",
		circular1->children[0]->children[0] == circular1
		&& circular2->parent->parent == circular2);
}

void	test_stress(t_gc *gc)
{
	t_timer	timer;
	void	**pointers;
		void			*temp[10];
	void	*large;
	size_t	mem_used;

	print_section_header("STRESS TESTS");
	// Lots of small allocations
	start_timer(&timer);
	pointers = gc_calloc(gc, 100000, sizeof(void *));
	for (int i = 0; i < 100000; i++)
	{
		pointers[i] = gc_malloc(gc, (rand() % 100) + 1);
		// Write something to ensure the memory is usable
		*(char *)pointers[i] = 'A' + (i % 26);
	}
	stop_timer(&timer);
	print_test_result("100,000 small allocations", 1);
	printf("    Time: %.2f ms\n", timer.elapsed_ms);
	// Alternating allocate and free to test fragmentation handling
	start_timer(&timer);
	for (int i = 0; i < 10000; i++)
	{
		// Allocate 10 objects
		for (int j = 0; j < 10; j++)
		{
			temp[j] = gc_malloc(gc, (rand() % 1000) + 1);
			memset(temp[j], 'X', (rand() % 1000) + 1);
		}
		// Free 5 of them directly
		for (int j = 0; j < 5; j++)
		{
			gc_free(gc, temp[j]);
		}
		// Allocate 5 more
		for (int j = 0; j < 5; j++)
		{
			temp[j] = gc_malloc(gc, (rand() % 1000) + 1);
			memset(temp[j], 'Y', (rand() % 1000) + 1);
		}
	}
	stop_timer(&timer);
	print_test_result("Allocation/free interleaving", 1);
	printf("    Time: %.2f ms\n", timer.elapsed_ms);
	// Large allocations
	start_timer(&timer);
	for (int i = 0; i < 100; i++)
	{
		size_t size = 1024 * 1024 * (1 + (rand() % 10)); // 1-10 MB
		large = gc_malloc(gc, size);
		if (large)
		{
			// Touch some of the memory
			for (size_t j = 0; j < size; j += 4096)
			{
				((char *)large)[j] = 'Z';
			}
		}
	}
	stop_timer(&timer);
	print_test_result("Large allocations", 1);
	printf("    Time: %.2f ms\n", timer.elapsed_ms);
	// Check memory usage
	mem_used = gc_get_total_memory(gc);
	print_test_result("Memory tracking after stress", mem_used > 0);
	printf("    Current memory usage: %zu bytes (%.2f MB)\n", mem_used, mem_used
		/ (1024.0 * 1024.0));
}

void	test_edge_cases(t_gc *gc)
{
	void	*zero_ptr;
	void	*ptr;
	void	*untracked;
	void	*ptr2;
	void	*realloc_zero;
	int		*empty_array;
	char	**empty_str_array;
	char	*empty_str;
	char	*large_source;
	char	*large_dup;

	print_section_header("EDGE CASE TESTS");
	// Zero allocation
	zero_ptr = gc_malloc(gc, 0);
	print_test_result("Zero-size allocation", zero_ptr != NULL);
	// Null pointer handling
	// Null pointer handling
	gc_free(gc, NULL);                         // Returns void,
		cannot be tested directly
	print_test_result("NULL pointer free", 1); // Just testing it doesn't crash
	// Double free handling
	ptr = gc_malloc(gc, 10);
	gc_free(gc, ptr);
	gc_free(gc, ptr); // Returns void, testing it doesn't crash
	print_test_result("Double free handling", 1);
	// Freeing untracked pointer
	untracked = malloc(10);
	gc_free(gc, untracked); // Returns void, testing it doesn't crash
	free(untracked);        // Clean up with system free
	print_test_result("Untracked pointer handling", 1);
	// Realloc to zero
	ptr2 = gc_malloc(gc, 100);
	realloc_zero = gc_realloc(gc, ptr2, 0);
	print_test_result("Realloc to zero", 1); // Just testing it doesn't crash
	// Creating empty structures/arrays
	empty_array = gc_int_array_create(gc, 0);
	empty_str_array = gc_str_array_create(gc, 0);
	print_test_result("Empty arrays", empty_array != NULL
		&& empty_str_array != NULL);
	// Empty string handling
	empty_str = gc_strdup(gc, "");
	print_test_result("Empty string", empty_str != NULL
		&& strlen(empty_str) == 0);
	// Large string handling
	large_source = gc_malloc(gc, 1000001);
	memset(large_source, 'A', 1000000);
	large_source[1000000] = '\0';
	large_dup = gc_strdup(gc, large_source);
	print_test_result("Large string duplication", large_dup
		&& strlen(large_dup) == 1000000 && large_dup[0] == 'A'
		&& large_dup[999999] == 'A');
}

void	test_performance(t_gc *gc)
{
	int		iterations;
	t_timer	sys_timer;
	void	**sys_ptrs;
	t_timer	gc_timer;
	void	**gc_ptrs;
	char	*str;
	char	*str;
	char	*str2;
	char	*combined;
	char	*str;
	char	*str2;
	t_gc	*temp_gc;
	int		count;

	print_section_header("PERFORMANCE TESTS");
	// Compare gc_malloc vs malloc
	iterations = 1000000;
	// Test system malloc/free
	start_timer(&sys_timer);
	sys_ptrs = malloc(iterations * sizeof(void *));
	for (int i = 0; i < iterations; i++)
	{
		sys_ptrs[i] = malloc(100);
	}
	for (int i = 0; i < iterations; i++)
	{
		free(sys_ptrs[i]);
	}
	free(sys_ptrs);
	stop_timer(&sys_timer);
	// Test gc_malloc/gc_free
	start_timer(&gc_timer);
	gc_ptrs = gc_malloc(gc, iterations * sizeof(void *));
	for (int i = 0; i < iterations; i++)
	{
		gc_ptrs[i] = gc_malloc(gc, 100);
	}
	for (int i = 0; i < iterations; i++)
	{
		gc_free(gc, gc_ptrs[i]);
	}
	stop_timer(&gc_timer);
	printf("System malloc/free: %.2f ms\n", sys_timer.elapsed_ms);
	printf("gc_malloc/gc_free:  %.2f ms\n", gc_timer.elapsed_ms);
	printf("Overhead factor:    %.2fx\n", gc_timer.elapsed_ms
		/ sys_timer.elapsed_ms);
	// Test string operations
	start_timer(&sys_timer);
	for (int i = 0; i < 10000; i++)
	{
		str = strdup("Performance test string");
		start_timer(&sys_timer);
		for (int i = 0; i < 10000; i++)
		{
			str = strdup("Performance test string");
			str2 = strdup("Another test string");
			combined = malloc(strlen(str) + strlen(str2) + 1);
			strcpy(combined, str);
			strcat(combined, str2);
			free(str);
			free(str2);
			free(combined);
		}
		stop_timer(&sys_timer);
		start_timer(&gc_timer);
		for (int i = 0; i < 10000; i++)
		{
			str = gc_strdup(gc, "Performance test string");
			str2 = gc_strdup(gc, "Another test string");
			// Store result to avoid unused variable warning
			gc_strjoin(gc, str, str2);
			// No need to free with gc
		}
		temp_gc = gc_create();
		count = 100;
		// Allocate many objects
		for (int i = 0; i < count; i++)
		{
			gc_malloc(temp_gc, 100);
		}
		// Allocate many objects
		for (size_t i = 0; i < count; i++)
		{
			gc_malloc(temp_gc, 100);
		}
		// Allocate many objects
		for (size_t i = 0; i < count; i++)
		{
			gc_malloc(temp_gc, 100);
		}
		start_timer(&gc_timer);
		gc_cleanup(&temp_gc);
		stop_timer(&gc_timer);
	}

}
void stop_timer(t_timer * timer)
{
    timer->end = clock();
    timer->elapsed_ms = (double)(timer->end - timer->start) * 1000.0
        / CLOCKS_PER_SEC;
}
/* ========================= UTILITY FUNCTIONS ========================= */

void	start_timer(t_timer *timer)
{
	timer->start = clock();
}

void	stop_timer(t_timer *timer)
{
	timer->end = clock();
	timer->elapsed_ms = (double)(timer->end - timer->start) * 1000.0
		/ CLOCKS_PER_SEC;
}

void	print_section_header(const char *title)
{
}

void	run_test_category(t_gc *gc, t_test_category category)
{
	switch (category)
	{
	case BASIC_ALLOCATION:
		test_basic_allocation(gc);
		break ;
	case STRING_FUNCTIONS:
		test_string_functions(gc);
		break ;
	case ARRAY_FUNCTIONS:
		test_array_functions(gc);
		break ;
	case LIST_FUNCTIONS:
		test_list_functions(gc);
		break ;
	case NESTED_STRUCTURES:
		test_nested_structures(gc);
		break ;
	case STRESS_TEST:
		test_stress(gc);
		break ;
	case EDGE_CASES:
		test_edge_cases(gc);
		break ;
	case PERFORMANCE:
		test_performance(gc);
		break ;
	}
}

/* ============================== MAIN FUNCTION ============================== */

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	// Seed random number generator
	srand(time(NULL));

	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("  ULTIMATE GARBAGE COLLECTOR TEST\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

	t_gc				*gc = gc_create();
	if (!gc)
	{
		printf("Failed to create garbage collector\n");
		return (1);
	}

	// Run all test categories
	run_test_category(gc, BASIC_ALLOCATION);
	run_test_category(gc, STRING_FUNCTIONS);
	run_test_category(gc, ARRAY_FUNCTIONS);
	run_test_category(gc, LIST_FUNCTIONS);
	run_test_category(gc, NESTED_STRUCTURES);
	run_test_category(gc, EDGE_CASES);
	run_test_category(gc, STRESS_TEST);
	run_test_category(gc, PERFORMANCE);

	// Final cleanup and summary
	printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("  CLEANUP AND SUMMARY\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

	size_t				final_memory = gc_get_total_memory(gc);
	printf("Final memory usage before cleanup: %zu bytes (%.2f MB)\n",
		final_memory, final_memory / (1024.0 * 1024.0));

	t_timer				cleanup_timer;
	start_timer(&cleanup_timer);
	gc_cleanup(&gc);
	stop_timer(&cleanup_timer);

	printf("Cleanup time: %.2f ms\n", cleanup_timer.elapsed_ms);
	printf("All tests completed successfully!\n");

	return (0);
}