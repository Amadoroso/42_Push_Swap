*This project has been created as part of the 42 curriculum by apinho-a*

# Libft


## Description

**Libft** is a user defined custom C library containing reimplementations of standard `libc` functions and additional utility tools. It serves as the foundational library for all future C projects in the 42 curriculum.

### Libft.h overview

- **Part 1**: Replication of standard `string`, and `stdlib` functions, such as `ft_strlen`, `ft_memset` and `ft_atoi`.

- **Part 2**: Non-standard utility functions for string manipulation and memory, such as `ft_split`, `ft_strjoin` and `ft_itoa`.

- **Part 3**: A complete set of functions to handle linked lists using a custom `t_list` structure defined in the `libft.h` file.

>[!NOTE]
>All code adheres to **42 Norm** and can be compiled into a `libft.a` static library using a provided `Makefile`.


## Instructions

### Libft.a compilation

**To compile `libft.h` into an archive use:** `make libft.a` or `make`.

### File removal

**To remove any `ft*.o` file use:** `make clean`.

**To remove `libft.a` and any `ft_*.o` file use:** `make fclean`.

### Compiling with libft.a

**To compile a program that uses a function from libft.a file**: `cc -Wall -Wextra -Werror code.c libft.a -o program.out`

## Resources

### References

- **[W3 School C](https://www.w3schools.com/c/index.php)** course was mainly used to understand novel C concepts;
- **[SYNTAX Unlocking session](https://github.com/Carlos-o-Grande/Unlocking_Sessions-42_School_Kick-Off)** Deep-dive into Syntax by a fellow 42 colleague;
- **[Makefile Tutorial](https://makefiletutorial.com/)** is a fantastic guide to understanding Makefile.

### LLM Usage Disclosure

The learning process was accelerated by `Google Gemini 3.1 Pro` by helping with:
- **Conceptual Breakdown:** Simplifying complex C architecture and memory management principles;
 - **Logic Verification:** Simulating edge cases and explain potential undefined behaviors;
 - **Debbuging:** Assisting in the breakdown and analysis of bugs.