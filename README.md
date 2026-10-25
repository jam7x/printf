*This project has been created as part of the 42 curriculum by bpaineau.*

# ft_printf

## Description

ft_printf is a reimplementation of the libc `printf()` function, packaged as a
static library (`libftprintf.a`). The prototype is:

```c
int ft_printf(const char *, ...);
```

Supported conversions: `c s p d i u x X %`. Like the original, the function
returns the number of characters printed. The buffer management of the real
`printf()` is not reimplemented: every piece of output goes straight through
`write`.

## Instructions

```sh
make        # builds libftprintf.a at the root of the repository
make clean  # removes the object files
make fclean # removes the object files and the library
make re     # fclean + all
```

Use it in your own program:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are %d\n", "world", 42);
	return (0);
}
```

```sh
cc main.c -L. -lftprintf -o test
```

## Algorithm and data structures

- **Parsing**: a single linear pass over the format string. Normal characters
  are written directly. When `%` is found, the next character selects a
  conversion in a small dispatcher (`ft_dispatch`).
- **Arguments**: handled with `va_list` / `va_arg`. The `va_list` is passed
  by pointer to the dispatcher, so the position in the argument list is kept
  between calls.
- **Numbers**: one recursive function, `ft_putnbr_base`, converts an
  `unsigned long` to any base given as a string of digits. It serves `%u`,
  `%x`, `%X`, `%p` and, after the sign is handled in a `long`, `%d`/`%i`
  (this avoids the `INT_MIN` overflow).
- **Return value**: each `ft_print_*` function returns the number of
  characters it wrote (or -1 if `write` fails). `ft_printf` sums them.

No complex data structure is needed: the whole job is a linear scan plus
recursion on the digits.

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- GNU make manual: https://www.gnu.org/software/make/manual/
- AI usage: <describe honestly here which tasks AI helped with, for example
  explaining the architecture and writing/commenting the code, and what you
  reviewed or tested yourself>
