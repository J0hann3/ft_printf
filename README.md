<h1 align=center>💻 Ft_printf</h1>
<p align="center">
  <img src="img/ft_printf.png?raw=true"/>
</p>

## About
>The goal of this project is pretty straightforward. You will recode printf().
>You will mainly learn about using a variable number of arguments. How cool is that??
>It is actually pretty cool :)

[Subject Ft_Printf Project 42](ft_printf.pdf)

## Setup

```
git clone https://github.com/J0hann3/ft_printf.git
cd ft_printf
make
gcc main.c libftprintf.a
```

`make` will create librairy call **libftprintf.a**

This printf handle only the following convertion:
 - `%d` for the integer
 - `%i` for the integer
 - `%c` for the char
 - `%s` for the string
 - `%u` for the unsigned integer
 - `%p` for the address/pointer
 - `%x` for hexadecimal in lowercase
 - `%X` for hexadecimal in uppercase
 - `%%` to print %
