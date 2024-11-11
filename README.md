<h1 align=center>💻 Ft_printf</h1>
<p align="center">
  <img src="img/ft_printf.png?raw=true" alt="Ft_Printf Project Image"/>
</p>

## About
>The goal of this project is pretty straightforward. You will recode printf().
>You will mainly learn about using a variable number of arguments. How cool is that??
>It is actually pretty cool :)

[Subject Ft_Printf Project 42](ft_printf.pdf)


The `ft_printf` function allows formatted printing to standard output, similar to the standard `printf`.

## Features
- **Description**: Prints strings and variable values to standard output.
- **Feature**: Uses variadic functions to handle a flexible number of arguments, enabling dynamic and customizable printing.
- **How to Use**: Use `ft_printf` exactly like `printf`, simply pass the format string as the first argument and any additional variables as needed.

## Setup

**Clone the Repository**:

```bash
git clone https://github.com/J0hann3/ft_printf.git
cd ft_printf
make
```

## Usage

- To use `ft_printf`, pass a format string as the first argument, followed by any variables to include in the output. For example:
```C
ft_printf("Integer: %d\nString: %s\n", 10, "hello")
```
- Include the following line in your file to access the function:
```C
#include "ft_printf.h"
```
- Compile your project, and link it with `libftprintf.a`
```bash
gcc main.c libftprintf.a
```

- `ft_printf` currently supports the following conversions:
 - `%d` for the integer
 - `%i` for the integer
 - `%c` for the char
 - `%s` for the string
 - `%u` for the unsigned integer
 - `%p` for the address/pointer
 - `%x` for hexadecimal in lowercase
 - `%X` for hexadecimal in uppercase
 - `%%` to print %

- `ft_printf` returns a `int` representing the number of characters printed to standard output

## New Notion

### va_arg
This project introduces va_arg and variadic functions, allowing a function to accept a variable number of arguments. Here’s an overview of how it works:
- Create a function with an undefined number of arguments
```C
int	ft_printf(const char *str, ...);
```
- Initialize va_arg, where `str` is the first parameter before the variadic list
```C
va_list elem;
va_start(elem, str);
```
- Extract variable depending of the type in the first string
```C
va_arg(elem, int)
```
- Destroy the list before the end of the function
```C
va_end(elem)
```