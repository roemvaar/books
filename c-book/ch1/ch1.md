# Chapter 1 - A Tutorial Introduction

The only way to learn a new programming language is by writing programs in it.

A C program consists of:

- Functions: Contains statements that specify the computing operations to be done
- Variables: Store values during the computation

You are at the liberty to give functions whatever name you like, but you have to specify
'main' - is a special function - because your program begins executing at the beginning 
of main. Every program must have a main.

Main will usually call other functions to complete its job. One method of communicating 
data between functions is for the calling function to provide a list of values, called arguments.

The statements of a function are enclosed in braces {}.

If an arithmetic operator has integer operands, an integer operation is performed.
If an arithmetic operator has one floating-point operand and one integer operand, however,
the integer will be converted to floating point before the operation is done. Writing
floating-point constants with explicit decimal points even when they have integral
values emphasizes floating-point nature for human readers.

The choice between *while* and *for* is arbitrary, based on which seems clearer.
The *for* is usually appropriate for loops in which the initialization and increment
are single statements and logically related, since it is more compact than *while* and
it keeps the loop control statements together in one place.

One of the nice things about while and for is that they test at the top of the loop, before
proceeding with the body. If there's nothing to do, nothing is done, even if it means never
going through the loop body.

The grammatical rules of C require that a for statement have a body. If nothing needs to be
done at the body of the *for loop*, you can add a *null statement*, i.e. an isolated
semicolon, to satisfy the requirement, as you can see in the following example:

```c
    #include <stdio.h>


    // Count characters in input
    int main(void)
    {
        long nc;

        for(nc = 0; getchar() != EOF; ++nc)
        {
            ;
        }

        printf("%d\n", nc);

        return 0;
    }

```

It's bad practice to bury "magic numbers" in a program; they convey little information to 
someone who might have to read the program later, and they are hard to change in a
systematic way. One way to deal with magic numbers is to give them meaningful names. 

A *#define* line defines a *symbolic name* or *symbolic constant* to be a particular string
of characters:

```c
    #define name replacement text
```

Thereafter, any occurrence of *name* will be replaced by the corresponding replacement
text. (At the preprocessing stage of the compilation process).

The model of input and output supported by the standard library is very simple. Text input
or output, regardless of where it originates or where it goes to, is dealt with as streams
of characters. A **text stream** is a sequence of characters divided into lines; each line
consists of zero or more characters followed by a new line character.

The statement

```c
    ++nc;
```

presents a new operator, ++, which means *increment by one*. You could instead write

```c
    nc = nc + 1;
```

but ++nc is more concise and often more efficient. There is a corresponding operator -- to
decrement by one. The operators can be either prefix operators (++nc) or postfix (nc++);
these two forms have different values in expressions.

The if statement tests the parenthesized condition, and if the condition is true, executes
the statement (or group statements in braces) that follows.

The double equals sign *==* is the C notation for "is equal to". This symbol is different
than the single *=* symbol that C uses for assignment.

The **logical operators** available in c are:

- **&&** AND
- **||** OR
- **!** NOT

The operator && has higher precedences than the || operator. Expressions connected by &&
or || are evaluated left to right, and it is guaranteed that evaluation will stop as soon
as the truth or falsehood is known.

The following example shows an if-else statement. *else* specifies an alternative action
if the condition part of an if statement is false.

```c
    if(expression)
        statement1
    else
        statement2

```

One and only one of the two statements associated with an if-else is performed. If the
*statement* is true, *statement1* is executed; if not, *statement2* is executed. Each
statement can be a single statement or several in braces.

**Exercise 1.11** How would you test the word count program? What kind of input are most
likely to uncover bugs if there are any?

[Tests](https://www.harishnote.com/2015/09/k-exercise-111-testing-word-count.html):

  - Test 1: No input
  - Test 2: One line without enter, i.e. without new line
  - Test 3: One line
  - Test 4: Multiple line
  - Test 5: One big word as input

In C, simple quotes *' '* delimit a single characters whereas double quotes *" "* are for
strings.

**Arrays:**

The declaration

```c
    int ndigit[10];
```

declares ndigit to be an array of 10 integers. Array subscripts always start at zero in C.

