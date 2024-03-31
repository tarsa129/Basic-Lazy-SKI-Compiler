# Compilers Class Final Project - Lazy SKI Compiler

This project aims to build a simple lazy SKI compiler, done as a final project for a compilers class.

## Language Overview
The language is a purely applicative language, meaning that there are no side effects like input/output. It also features lazy evaluation. The syntax consists of S, K, I, B, and C combinators, various primitives, integers and booleans as basic data types, a single, generic error, and anonymous functions with single character variables. The following primitives are included:
* plus x y → x + y (x and y must be integers).
* add1 x → x + 1 (x must be an integer).
* sub1 x → x - 1 (x must be an integer).
* eq x y → (x == y) (x and y must either both be integers or both be booleans.)
* cond x y z
** If x evaluates to “true”, then cond x y z → y
** If x evaluates to “false”, then cond x y z → z
** If x evaluates to neither, then cond x y z → err
** y and z do not need to have the same type

To apply an argument to a function, write the functions and then the arguments, delimited by spaces. For example, “plus 2 3” will result in 5. Parenthesis should be used if an argument itself is an expression and not a single value. For example, “plus (add1 1) 3” will also result in 5. Needless parentheses should be avoided. 

To define an anonymous function, put squiggly brackets around the function definition. Right after the open squiggly brackets, put the variables (each of which must be a single, non-numeric character), in brackets. Then, put the function body. For example, {[x y] plus x y} is an anonymous function that will add two numbers. One or two variables need to be in the brackets. This compiler will automatically bracket abstractions of anonymous functions. Anonymous functions can be nested up to three layers due to a hardcoded memory limit, which can easily be increased. 

Code must be placed in the provided prog.txt file, and the program can be no more than 500 characters, including whitespace.  If an error occurs during program execution, the output to the console will be “err occurred”. If the program terminates with a value, then the value will be printed to the console. The code must be syntactically correct; syntactically incorrect programs result in undefined behavior. Additionally, the code must result in a value or error; programs that do not do that result in undefined behavior.

## Building
This program can be built with any C compiler. During development, the gcc compiler version 9.3.0 on an Ubuntu Windows subsystem was used. Once the executable has been built, it can be run without any other arguments. 
