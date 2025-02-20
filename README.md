# Libft, ft_printf & get_next_line

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

---

## Additional Utilities

This repository also includes several mathematical and vector utility functions that handle:
- Cross products  
- Dot products  
- Normalization  
- Various isometric transformations

These utilities can serve as a foundation for projects involving basic 3D computations.

---

## Build & Documentation

- **Makefile:**  
  The project is built using a robust Makefile that organizes the source code into modular directories.

- **Documentation:**  
  Every function is documented using Doxygen-style comments, ensuring clarity and ease of use for developers.

---

## Who Is This For?

This repository is ideal for anyone looking to:
- Understand the fundamentals of low-level C programming.
- Learn about memory management and data structures.
- Build and customize their own utility libraries.
- Explore custom implementations of widely used functions.

---

## Contributions

Contributions and feedback are welcome! Feel free to fork the repository, open issues, and submit pull requests to improve the project.

---

## License

This project is licensed under the MIT License. See the LICENSE file for details.

---

Happy coding!
