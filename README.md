*This project has been created as part of the 42 curriculum by mhinojos.*

# ft_printf

## Description

`ft_printf` is a simplified reimplementation of the C `printf` function. Its goal is to parse a format string, retrieve the corresponding variadic arguments, print each value to standard output, and return the number of printed characters.

The current implementation supports these conversions:

| Conversion | Output |
| --- | --- |
| `%c` | A character |
| `%s` | A string; a null pointer is printed as `(null)` |
| `%p` | A pointer in lowercase hexadecimal, prefixed with `0x` (an adress) |
| `%d`, `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned hexadecimal integer with lowercase letters |
| `%X` | An unsigned hexadecimal integer with uppercase letters |
| `%%` | A literal percent sign |

This version does not implement format flags, field width, precision, or length modifiers. A trailing `%` with no conversion character is ignored.

## Instructions

### Build

From this directory, run:

```sh
make
```

This creates the static library `libftprintf.a`. Remove the object files and library with:

```sh
make fclean
```

### Use

Include `ft_printf.h` and link the library when compiling a program:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s: %d\n", "42", 42);
	return (0);
}
```

For a `main.c` file in this directory:

```sh
cc -Wall -Wextra -Werror -I. main.c -L. -lftprintf -o example
./example
```

## Resources

- [POSIX `printf` / `fprintf` specification](https://pubs.opengroup.org/onlinepubs/9799919799/functions/fprintf.html) — reference for formatted output and conversion specifications.
- [Linux `stdarg(3)` manual](https://man7.org/linux/man-pages/man3/stdarg.3.html) — reference for `va_list`, `va_start`, `va_arg`, and `va_end`.
- 42 subject and course materials — project requirements and allowed-function constraints.

### AI usage

AI assistance was used to review the implementation and explain variadic arguments, hexadecimal conversion, pointer formatting, and character counting. It was also used to help draft and organize this README. The code was written and adapted by the student; AI suggestions were reviewed against the project files.
