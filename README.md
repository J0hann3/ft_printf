# ft_printf

>The goal of this project is pretty straightforward. You will recode printf().
>You will mainly learn about using a variable number of arguments. How cool is that??
>It is actually pretty cool :)

[Subject Prinft Project 42](https://cdn.intra.42.fr/pdf/pdf/105483/en.subject.pdf)

## Makefile

```
git clone https://github.com/J0hann3/ft_printf.git
cd ft_printf
make
gcc main.c libftprintf.a
```

`make` will create librairy call **libftprintf.a**

To use this librairy in your code, you can include this :
```
#include "get_next_line.h
```

This printf handle only this convertion :
 - %d for the integer
 - %i for the integer
 - %c for the char
 - %s for the string
 - %u for the unsigned integer
 - %p for the address/pointer
 - %x for hexadecimal in lowercase
 - %X for hexadecimal in uppercase
 - %% to print %
