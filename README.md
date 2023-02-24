# Printf
# Project Overview <br>
The ft_printf project is a C language implementation of the printf function. The printf function is used to format and print data to the console. The ft_printf implementation provides a way for C programmers to create formatted output for their programs.<br>

The ft_printf implementation includes support for several format specifiers, including: <br>

* %c: prints a single character <br>
* %s: prints a string <br>
* %d: prints a decimal integer <br>
* %u: prints an unsigned decimal integer <br>
* %x: prints a hexadecimal integer (lowercase) <br>
* %X: prints a hexadecimal integer (uppercase) <br>
* %p: prints a pointer address <br>
* The ft_printf implementation also includes support for various formatting options, such as field width and precision. <br>

# Project Structure <br> 
The ft_printf project is structured as follows: <br>

libft: This folder contains a library of functions that are used by the ft_printf implementation. The library includes functions for memory management, string manipulation, and character manipulation, among other things. <br>
ft_printf: This folder contains the implementation of the ft_printf function. The implementation is split into several files, each of which is responsible for a different part of the implementation. <br>
Makefile: This file contains the build instructions for the project. <br>
# How to Use <br>
To use the ft_printf implementation in your own C program, you must first compile the library using the Makefile. To do this, navigate to the root folder of the project in a terminal and type make. <br>

Once the library has been compiled, you can include the ft_printf header file in your C program and call the ft_printf function as you would the printf function. For example: <br>

#include "ft_printf.h" <br>

int main(void) <br> 
{ <br>
    ft_printf("Hello, world!\n"); <br>
    return (0); <br>
} <br>
# How to Test <br> 
The ft_printf implementation comes with a suite of test cases to ensure that it is working correctly. To run the test cases, navigate to the root folder of the project in a terminal and type make test. <br>

The test suite includes tests for each of the format specifiers and various formatting options. The test results will be displayed in the terminal, indicating which tests have passed and which have failed. <br>

# Conclusion <br>
The ft_printf project is a useful implementation of the printf function that provides C programmers with a way to format and print output to the console. The implementation includes support for several format specifiers and formatting options and is backed by a suite of test cases to ensure its correctness. <br>
