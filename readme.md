# Notes on C Programming

## Installation
### Compiler
### Preparing Code Editor / IDE

## Program structure
### Include Directive
### The `main()` function

## Running a program
- Source code
- Compilation
- Linking
- Execution

## Data types
- Primitive
- Compound / User defined

## struct (Structure)

## union

## enum (Enumerator)

## Variable
 - Declaration
 - Initialization
 - Casting

## Input & output (IO)

## Array
- Fixed Length Array
- One Dimensional Array
- Multi-dimensional Array
- Variable Length Array (VLA)
- Dynamic Array

## Character & string
### Format Specifier
### Conversion Specifier

## Function
### Definition
- Return type
- Name
- Parameters
- Variadic function

## Special
- Type Cast
- Incomplete Type
- Compound Literal
- Designated Initialization

## Headers

## Storage Classes
Only one storage class may appear in a declaration. If present it should come first.

- auto
- static
- extern
- register (variable only)

## Type Qualifiers
A declaration may contain zero or more type qualifiers.

- const
- volatile
- restrict
- inline (function only)

## Type Specifiers
- void
- char
- short
- int
- long
- float
- double
- signed
- unsigned

## Scope
- File
- Block
- Function prototype
- Function
- Nested

## Storage Duration
- Automatic
- Static
- Thread
- Dynamic

## Linkage
- Internal
- External

## Operator Precedence
- [Postfix Operators](./docs/operator-precedence.md#postfix-operators)
- [Unary Operators](./docs/operator-precedence.md#unary-operators)
- [Multiplicative Operators](./docs/operator-precedence.md#multiplicative-operators)
- [Additive Operators](./docs/operator-precedence.md#additive-operators)
- [Shift Operators](./docs/operator-precedence.md#shift-operators)
- [Relational Operators](./docs/operator-precedence.md#relational-operators)
- [Equality Operators](./docs/operator-precedence.md#equality-operators)
- [Bitwise Operators](./docs/operator-precedence.md#bitwise-operators)
- [Conditional Operator](./docs/operator-precedence.md#conditional-operator)
- [Assignment Operators](./docs/operator-precedence.md#assignment-operators)
- [Comma Operator](./docs/operator-precedence.md#comma-operator)

## Bitwise Operators
- [AND (&)](./docs/bitwise.md#and-)
- [OR (|)](./docs/bitwise.md#or-)
- [NOT (~)](./docs/bitwise.md#not-)
- [SHIFT LEFT (<<)](./docs/bitwise.md#shift-left-)
- [SHIFT RIGHT (>>)](./docs/bitwise.md#shift-right-)

## Memory
- [Random Access Memory (RAM)](./docs/memory.md#random-access-memory-ram)
- [Stack](./docs/memory.md#stack)

## Pointer & reference
- Pointer type
- Reference
- Pointer & value
- Pointer & array
- [Pointer & function](./docs/pointer-reference.md#pointer--function)
- Pointer & struct
- Pointer to pointer
- Constant pointer

## Dynamic memory management
- [malloc()](./docs/dynamic-memory.md#malloc)
- calloc()
- realloc()
- free()

### Others:
- alloca()
- aligned_alloc()
- reallocarray()

## Memory management issues
- [Dangling pointer](./docs/memory-issuess.md#dangling-pointer)
- [Memory leak](./docs/memory-issuess.md#memory-leak)
- [Double free](./docs/memory-issuess.md#double-free)
- [Buffer overflow / Memory overrun](./docs/memory-issuess.md#buffer-overflow--memory-overrun)
- Memory Fragmentation
- Memory Access Violations
- Uninitialized Pointers
- Resource Leaks
- Race Conditions
- Stack Overflow
- Use-After-Free
- Wild Pointers
- Out-of-Memory Errors
- Memory Corruption

## Macro
## Preprocessor directives

## Error Handling
- [Condition](./docs/error-handling.md#condition)
- [assert](./docs//error-handling.md#assert)
- [errno](./docs/error-handling.md#errorno)
  - [perror](./docs/error-handling.md#perror)
  - [strerror](./docs/error-handling.md#strerror)
- [Signal](./docs/error-handling.md#signal)
  - [handler](./docs/error-handling.md#handler)
  - [raise](./docs/error-handling.md#raise)
- setjmp & longjmp

## Date & time

## Debugging

## Threads

## Portability

## Data structures

## Algorithms

## Object Oriented Programming (OOP)
- [Abstraction](./docs/abstraction.md)
- [Encapsulation](./docs/encapsulation.md)
- [Inheritance](./docs/inheritance.md)
- [Polymorphism](./docs/polymorphism.md)

## Standard library
### C89/C90 Standard Library Headers

These are the original headers introduced in **ANSI C** (C89/C90), which remain widely used.

| Header       | Description                                                                                  |
| ------------ | -------------------------------------------------------------------------------------------- |
| `<assert.h>` | Provides the `assert` macro for debugging purposes.                                          |
| `<ctype.h>`  | Functions for character classification and conversion, such as `isalpha` and `toupper`.      |
| `<errno.h>`  | Defines macros for error handling, like `errno`.                                             |
| `<float.h>`  | Defines limits of floating-point types, like `FLT_MAX`.                                      |
| `<limits.h>` | Defines limits for fundamental types, like `INT_MAX`.                                        |
| `<locale.h>` | Functions for setting and using locale information, such as `setlocale`.                     |
| `<math.h>`   | Mathematical functions, including `sin`, `cos`, `sqrt`, etc.                                 |
| `<setjmp.h>` | Provides `setjmp` and `longjmp` for non-local jumps (used in exception handling).            |
| `<signal.h>` | Signal handling functions, like `signal` and `raise`.                                        |
| `<stdarg.h>` | Support for variable argument functions using `va_list`, `va_start`, and `va_end`.           |
| `<stddef.h>` | Common definitions like `NULL`, `size_t`, and `ptrdiff_t`.                                   |
| `<stdio.h>`  | Standard input/output functions, including `printf`, `scanf`, `fopen`, etc.                  |
| `<stdlib.h>` | General utilities, including memory management (`malloc`), program control, and conversions. |
| `<string.h>` | String manipulation functions like `strlen`, `strcpy`, `strcat`, etc.                        |
| `<time.h>`   | Date and time functions, including `time`, `clock`, and `difftime`.                          |

### C95 Standard Library Headers

**C95** introduced some additional headers to support new data types and wide characters.

| Header       | Description                                                                        |
| ------------ | ---------------------------------------------------------------------------------- |
| `<iso646.h>` | Defines alternative spellings for operators (e.g., `and` for `&&`).                |
| `<wchar.h>`  | Functions for handling wide characters and strings, including `wprintf`, `wcscpy`. |
| `<wctype.h>` | Functions for classifying wide characters, such as `iswalpha`.                     |

### C99 Standard Library Headers

The **C99** standard introduced several headers for complex numbers, type-generic math, and fixed-width integer types.

| Header         | Description                                                                                             |
| -------------- | ------------------------------------------------------------------------------------------------------- |
| `<complex.h>`  | Complex number types and operations, like `cabs` and `cimag`.                                           |
| `<fenv.h>`     | Functions to control floating-point environment (rounding, exceptions).                                 |
| `<inttypes.h>` | Format macros and extended integer types, such as `int64_t`.                                            |
| `<stdbool.h>`  | Defines `bool`, `true`, and `false` for Boolean operations.                                             |
| `<stdint.h>`   | Fixed-width integer types like `int32_t`, `uint8_t`.                                                    |
| `<tgmath.h>`   | Type-generic macros for math functions (e.g., `sqrt` can work on `float`, `double`, and `long double`). |

### C11 Standard Library Headers

The **C11** standard introduced threads, atomics, and better support for Unicode.

| Header            | Description                                                                     |
| ----------------- | ------------------------------------------------------------------------------- |
| `<stdalign.h>`    | Defines macros for specifying alignment (e.g., `alignas`).                      |
| `<stdatomic.h>`   | Atomic operations for multi-threaded programming.                               |
| `<stdnoreturn.h>` | Defines `noreturn` for functions that do not return (e.g., `exit`).             |
| `<threads.h>`     | Thread support library, including `thrd_t` and functions for thread management. |
| `<uchar.h>`       | Support for Unicode characters, including types like `char16_t` and `char32_t`. |

### C23 Standard Library Headers

The **C23** standard introduces improvements and some additional features to ease programming tasks. (Note: Some of these may still be tentative or implementation-specific in C23.)

| Header          | Description                                                                                             |
| --------------- | ------------------------------------------------------------------------------------------------------- |
| `<stdckdint.h>` | Checked integer arithmetic functions to handle overflow in integer operations safely.                   |
| `<stdfloat.h>`  | Defines standardized floating-point types with specific precision, such as `float32_t` and `float64_t`. |

## Books & Resources (Recommendation)
### Books
| Title                            | Edition | Year | Author(s)                               | Audience     | C Version |
| -------------------------------- | ------- | ---- | --------------------------------------- | ------------ | --------- |
| C Programming: A Modern Approach | 2nd     | 2009 | K. N. King                              | Everyone     | Up to C99 |
| Modern C for Absolute Beginners  | 2nd     | 2024 | Slobodan Dmitrović                      | Beginner     | Up to C23 |
| Intermediate C Programming       | 2nd     | 2024 | Yung-Hsiang Lu, George K. Thiruvathukal | Everyone     | Up to C23 |
| Tiny C Projects                  | 1st     | 2022 | Dan Gookin                              | Intermediate | Up to C23 |


#### Classics
Books listed here are classics. They are considered the best so far, but unfortunately they are extremely outdated. Some of the topics and methods might not be relevant, deprecated or removed. They are mostly published 30-50 years ago (some more or less).

| Title                                | Edition  | Year       | Author(s)                             | Audience | C Version |
| ------------------------------------ | -------- | ---------- | ------------------------------------- | -------- | --------- |
| The C Programming Language           | 1st, 2nd | 1978, 1988 | Brian W. Kernighan, Dennis M. Ritchie | Everyone | Up to C89 |
| C Programming: A Modern Approach     | 1st      | 1996       | K. N. King                            | Everyone | Up to C89 |
| Expert C Programming: Deep C Secrets | 1st      | 1994       | Peter van der Linden                  | Expert   | Up to C89 |
