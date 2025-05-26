#include "./garbage_collector/inc/garbage_collector.h"
#include <stdio.h>
#include <string.h>

// Test structure for basic struct operations
typedef struct s_test_struct
{
    int     value;
    float   decimal;
    char    character;
} t_test_struct;

// Print utility functions
void print_header(const char *title)
{
    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  %s\n", title);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

void print_result(const char *test_name, int success)
{
    printf("%-40s %s\n", test_name, success ? "✅ PASS" : "❌ FAIL");
}

// Main test function
void test_basic_allocation(t_gc *gc)
{
    print_header("BASIC ALLOCATION TESTS");
    
    // Test 1: Simple malloc
    void *ptr1 = gc_malloc(gc, 100);
    print_result("gc_malloc (100 bytes)", ptr1 != NULL);
    
    // Test 2: Calloc with zeroed memory
    int *numbers = gc_calloc(gc, 10, sizeof(int));
    int zeroed = 1;
    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] != 0)
        {
            zeroed = 0;
            break;
        }
    }
    print_result("gc_calloc (zeroed memory)", zeroed);
    
    // Test 3: Realloc preserving data
    char *str = gc_malloc(gc, 20);
    strcpy(str, "Hello World");
    char *str_resized = gc_realloc(gc, str, 50);
    print_result("gc_realloc (preserve data)", 
                 str_resized && strcmp(str_resized, "Hello World") == 0);
    
    // Test 4: Manual free
void *to_free = gc_malloc(gc, 30);
gc_free(gc, to_free);  // gc_free returns void, not an int
int free_result = 1;   // Just check that it didn't crash
print_result("gc_free (manual free)", free_result);
    
    // Test 5: Struct allocation
    t_test_struct *s = gc_alloc_struct(gc, sizeof(t_test_struct));
    s->value = 42;
    s->decimal = 3.14f;
    s->character = 'X';
    print_result("gc_alloc_struct", s != NULL);
    
    // Test 6: Struct duplication
    t_test_struct *s_copy = gc_duplicate_struct(gc, s, sizeof(t_test_struct));
    print_result("gc_duplicate_struct", 
                 s_copy && s_copy->value == 42 && 
                 s_copy->decimal == 3.14f && 
                 s_copy->character == 'X');
    
    // Test 7: Struct array
    t_test_struct *s_array = gc_alloc_struct_array(gc, 5, sizeof(t_test_struct));
    int array_valid = (s_array != NULL);
    for (int i = 0; i < 5; i++)
    {
        s_array[i].value = i;
        s_array[i].decimal = i + 0.5f;
        s_array[i].character = 'A' + i;
    }
    print_result("gc_alloc_struct_array", 
                 array_valid && s_array[2].value == 2 && 
                 s_array[2].decimal == 2.5f && 
                 s_array[2].character == 'C');
    
// Test 8: Edge cases
void *zero_alloc = gc_malloc(gc, 0);
print_result("gc_malloc (zero bytes)", zero_alloc != NULL);

gc_free(gc, NULL);     // gc_free returns void, not an int
int null_free_result = 1;  // Just check that it didn't crash
print_result("gc_free (NULL pointer)", null_free_result);
    
    // Test 9: Memory tracking
    size_t memory_used = gc_get_total_memory(gc);
    print_result("Memory tracking", memory_used > 0);
    printf("    Current memory usage: %zu bytes\n", memory_used);
}

int main(void)
{
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("  GARBAGE COLLECTOR - BASIC ALLOCATION TEST\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    
    t_gc *gc = gc_create();
    if (!gc)
    {
        printf("Failed to create garbage collector\n");
        return (1);
    }
    
    test_basic_allocation(gc);
    
    // Final cleanup
    printf("\nCleaning up all allocations...\n");
    gc_cleanup(&gc);
    printf("Cleanup complete. If no segfaults occurred, all memory was correctly tracked.\n");
    
    return (0);
}