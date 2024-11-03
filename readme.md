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

## Character & string
### Format Specifier
### Conversion Specifier

## Function
### Definition
- Return type
- Name
- Parameters
- Variadic function

## Headers

## Scope
- File
- Block
- Function prototype
- Function
- Nested

## Type Qualifiers
- const
- volatile
- restrict

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
- Dangling pointer
- Memory leak
- Double free
- Buffer overflow / Memory overrun
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
- Condition
- assert
- errno
  - perror
  - strerror
- Signal
  - handler
  - raise
- setjmp & longjmp

## Date & time

## Debugging

## Threads

## Portability

## Data structures

## Algorithms

## Standard library
- stdio.h
- stdlib.h
- sys/socket.h
- netdb.h
- ifaddrs.h

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
