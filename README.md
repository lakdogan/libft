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

### garbage_collector
- **Description:**  
  A comprehensive memory management system that automatically tracks and frees allocations.
- **Features:**  
  - Hash table-based pointer tracking for O(1) average lookup time
  - Wrapped memory allocation functions (malloc, calloc, realloc)
  - String and list operations with automatic memory management
  - Selective freeing of individual allocations
  - Batch cleanup of all managed memory
  - Memory usage statistics and tracking
- **Highlights:**  
  - Prevents memory leaks in complex applications
  - Simplifies memory management with a single cleanup call
  - High performance with over 10,000 allocations handled efficiently
  - Thread-safe design through non-global implementation
- **Example Usage:**
  ```c
  // Create a garbage collector
  t_gc *gc = gc_create();
  
  // Allocate memory that will be automatically tracked
  char *str = gc_strdup(gc, "Hello World");
  int *numbers = gc_malloc(gc, 5 * sizeof(int));
  
  // Use memory normally
  numbers[0] = 42;
  
  // Cleanup everything with a single call
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
