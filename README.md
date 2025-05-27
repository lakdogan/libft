# Libft, ft_printf , get_next_line & garbage_collector

This repository contains a custom C library implementation that re-creates a wide range of standard functions along with some additional utilities. It is designed to help you understand low-level C programming, memory management, and building custom utility libraries from scratch.

---

## Project Components

### Libft
- **Description:**  
  A collection of re-implemented standard C library functions.  
- **Features:**  
  - String manipulation  
  - Memory management  
  - Linked lists and more  
- **Code Quality:**  
  Functions are written with clear, concise, and well-commented code.

### ft_printf
- **Description:**  
  A custom implementation of the `printf` function.
- **Supported Format Specifiers:**  
  - `%c`: Character  
  - `%s`: String  
  - `%p`: Pointer  
  - `%d` / `%i`: Integer  
  - `%u`: Unsigned integer  
  - `%x` / `%X`: Hexadecimal  
  - `%%`: Literal `%`
- **Highlights:**  
  - Demonstrates the use of variable argument lists (`va_list`)  
  - Uses recursive techniques for printing hexadecimal numbers

### get_next_line
- **Description:**  
  A function that reads the next line from a file descriptor.
- **Features:**  
  - Supports multiple file descriptors simultaneously  
  - Efficiently reads and buffers file content

### Garbage Collector

- **Description:**  
  A comprehensive memory management system that automatically tracks and frees allocations, eliminating memory leaks and simplifying memory management in C.

- **Core Features:**  
  - Hash table-based pointer tracking with O(1) average lookup time
  - Thread-safe design through non-global implementation
  - Automatic expansion of tracking arrays
  - Complete memory lifecycle management
  - Zero-byte allocation handling

- **Memory Management Functions:**
  - Basic allocation: `gc_malloc`, `gc_calloc`, `gc_realloc`, `gc_free`
  - Memory operations: `gc_register`, `gc_memcpy`
  - Memory information: `is_valid_block`, `get_block_size`, `gc_get_total_memory`

- **String Operations:**
  - String creation: `gc_strdup`, `gc_substr`, `gc_itoa`
  - String manipulation: `gc_strjoin`, `gc_strjoin_3`, `gc_strtrim`
  - String parsing: `gc_split`

- **Array Management:**
  - 1D arrays: `gc_int_array_create`, `gc_int_array_dup`, `gc_str_array_create`, `gc_str_array_dup`
  - 2D arrays: `gc_int_matrix_create`, `gc_str_matrix_create`, `gc_str_matrix_dup`
  - 3D arrays: `gc_int_3d_create`, `gc_str_3d_create`
  - Array resizing: `gc_realloc_array`

- **List Operations:**
  - Node management: `gc_lstnew`, `gc_lstadd_back`, `gc_lstadd_front`
  - List manipulation: `gc_lstdup`, `gc_lst_from_array`, `gc_lstsub`, `gc_lstmap`

- **Generic Structure Handling:**
  - Structure operations: `gc_alloc_struct`, `gc_duplicate_struct`, `gc_alloc_struct_array`

- **Highlights:**  
  - Eliminates memory leaks in complex applications
  - Simplifies memory management with a single cleanup call
  - Handles complex nested data structures automatically
  - High performance with over 10,000 allocations handled efficiently
  - Extensively tested with comprehensive test suites
  - Complete documentation for all functions

- **Example Usage:**
  ```c
  // Create a garbage collector
  t_gc *gc = gc_create();
  
  // Basic memory operations
  char *str = gc_strdup(gc, "Hello World");
  int *numbers = gc_malloc(gc, 5 * sizeof(int));
  
  // Complex data structures
  int **matrix = gc_int_matrix_create(gc, 3, 4);
  matrix[0][0] = 42;
  
  // String operations
  char *joined = gc_strjoin(gc, str, " and Goodbye!");
  char **words = gc_split(gc, joined, ' ');
  
  // Linked lists
  t_list *list = NULL;
  gc_lstadd_back(gc, &list, "first item");
  gc_lstadd_back(gc, &list, "second item");
  
  // Custom structures
  typedef struct s_point { int x, y, z; } t_point;
  t_point *points = gc_alloc_struct_array(gc, 10, sizeof(t_point));
  points[0].x = 10;
  
  // Get memory usage statistics
  size_t memory_used = gc_get_total_memory(gc);
  printf("Current memory usage: %zu bytes\n", memory_used);
  
  // Clean everything up with a single call
  gc_cleanup(&gc);

---

## Additional Utilities

This repository includes a comprehensive set of utility functions organized in these categories:

### Vector Mathematics
- **Vector Operations:**
  - Cross products (ft_compute_cross_product, ft_normalized_cross_product)
  - Dot products (ft_dot_product)
  - Vector magnitude (ft_magnitude)
  - Normalization (ft_normalize, ft_unit_vector)
  - Vector angles (ft_vector_angle_deg, ft_vector_angle_rad)

- **Coordinate Transformations:**
  - Isometric projections (ft_isometric_x, ft_isometric_y)
  - Coordinate plane transformations (ft_newxy, ft_newxz, ft_newyx, ft_newyz, ft_newzx, ft_newzy)
  - Angle calculations (ft_tiltang)

- **Angle Utilities:**
  - Degree/radian conversions (ft_getdeg, ft_getrad)
  - Difference calculations (ft_getdif)

### Extended String Utilities
- **String Manipulation:**
  - String comparison (ft_strcmp)
  - Limited duplication (ft_strndup)
  - Safe joining (ft_safe_strjoin, ft_strjoin_three)
  - Split array cleanup (ft_free_split)

### Number Processing
- **Numeric Conversions:**
  - String to long conversion (ft_atol)
  - String to long long conversion (ft_strtoll)
  - Square root calculation (ft_sqrt)

### Character Classification
- **Extended Checks:**
  - Whitespace detection (ft_isspace)

### Memory Management
- **Advanced Allocation:**
  - Memory reallocation (ft_realloc)

These utilities serve as a foundation for projects involving 3D graphics, numerical computations, and advanced string processing.

## Build & Documentation

- **Makefile:**  
  The project is built using a robust Makefile that organizes the source code into modular directories.

- **Documentation:**  
  Every function is documented using Doxygen-style comments, ensuring clarity and ease of use for developers.

## Who Is This For?

This repository is ideal for anyone looking to:
- Understand the fundamentals of low-level C programming.
- Learn about memory management and data structures.
- Build and customize their own utility libraries.
- Explore custom implementations of widely used functions.
- Implement automatic memory management in C projects.
- Work with vector mathematics and coordinate transformations.

## Contributions

Contributions and feedback are welcome! Feel free to fork the repository, open issues, and submit pull requests to improve the project.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

Happy coding!