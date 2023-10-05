# # C Programming

## # Installation
### # Compiler
### # Preparing code editor / IDE

## # Program structure
### # The main() function

## # Headers

## # Standard library
### # <stdlib.h>
<stdlib.h> is a standard C library header that provides functions and macros for general-purpose programming tasks. It includes functions like malloc, free, exit, and utilities for random number generation, among others.

### # <stdio.h>
<stdio.h> is a standard C library header that contains functions and macros for performing input and output operations. It includes functions like printf, scanf, fopen, and more for reading and writing data to files and the console.

### # <sys/socket.h>
This header file provides functions, data structures, and constants for working with sockets in a Unix-like operating system. Sockets are a fundamental communication mechanism for networking in C.

### # <netdb.h>
The <netdb.h> header file contains functions and data structures for hostname resolution and DNS (Domain Name System) lookup. It's commonly used for converting between hostnames and IP addresses.

### # <ifaddrs.h>
This header file provides functions and data structures for retrieving information about network interfaces on a system. It allows you to enumerate and obtain details about all available network interfaces, including IP addresses and hardware addresses.

## # Running a program
### # Source code
### # Compilation
### # Linking
### # Execution

## # Data types
### # Primitive
### # Compound/user defined
### # Array

## # Variable

## # Constant
### # Enumerator (enum)

## # Function
### # Definition
#### # Return type
#### # Name
#### # Parameters
#### # Variable number of parameters

## # Memory
C supports 3 types of memory.

### # Static
### # Dynamic
### # Automatic

### # Scope and lifetime
#### # Global
#### # Static
#### # Dynamic
#### # Automatic

## # Dynamic memory allocation
### # malloc()
### # calloc()
### # realloc()
### # free()

## # Memory management issues
### # Memory leak
A memory leak occurs when a computer program doesn't release or "forget" memory it no longer needs. Over time, this unused memory accumulates and can lead to the program consuming more and more memory, slowing down the system or causing it to crash. Think of it as a gradual and silent resource waste that can harm a computer's performance if not resolved.

Memory leaks can become security risks because they expose sensitive data. When a program fails to release memory, confidential information like passwords or encryption keys can remain accessible in the system's memory. Attackers who gain access to this leaked data can exploit it to compromise security. Memory leaks thus affect both system performance and the potential for data breaches, underscoring the importance of proper memory management for cybersecurity.

### # Dangling pointer
A dangling pointer is a programming error that occurs when a pointer (a variable storing a memory address) continues to point to a memory location after that memory has been deallocated or freed. This can lead to unpredictable and potentially dangerous behavior, as the pointer may now point to invalid or reused memory, causing crashes or security vulnerabilities. Dangling pointers often arise when programmers don't properly update or nullify pointers after freeing the associated memory.

Avoiding dangling pointers is crucial for program stability and security, achieved through careful memory management practices and ensuring pointers are always valid or NULL when not in use.

### # Double free
Double free is a memory-related programming error where a program attempts to free, or deallocate, a memory address that has already been freed before. This can lead to serious issues like program crashes, data corruption, and even security vulnerabilities. When memory is freed, the program should mark it as available for reuse. However, attempting to free the same memory location twice can result in memory management problems.

To avoid double free errors, developers should keep track of memory allocation and deallocation carefully, ensuring that each allocated memory block is freed exactly once and not accessed after being freed.

### # Buffer overflow / Memory overrun
Buffer overflow is a security vulnerability that occurs when a program writes more data into a memory buffer, like an array, than it can hold. This excess data can overwrite adjacent memory, including critical program information or even code. In the hands of attackers, this can lead to remote code execution or unauthorized access to a system.

To prevent buffer overflows, developers must validate and limit the input data size, use secure coding practices, and implement bounds checking to ensure that data doesn't exceed the allocated buffer's capacity, thus safeguarding against potential security breaches and program crashes.

### # Memory Fragmentation
### # Memory Access Violations
### # Uninitialized Pointers
### # Resource Leaks
### # Race Conditions
### # Stack Overflow
### # Use-After-Free
### # Wild Pointers
### # Out-of-Memory Errors
### # Memory Corruption

## # Pointer & reference
### # Pointer type
### # Pointer to value
### # Reference of memory address
### # Pointer to array
### # Pointer to function
### # Pointer to structure (struct)
### # Pointer to pointer
### # Constant pointer

## # Input & output (IO)

## # Macro
## # Preprocessor directives

## # Debugging

## # Character & string
## # Date & time
## # Threads
## # Portability

## # Data structures
## # Algorithms
