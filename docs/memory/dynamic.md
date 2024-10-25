# Dynamic Memory Management
All memory allocation functions accept an argument of type size_t
that specifies the number of bytes of memory to be allocated.

## malloc()
The `malloc` function allocates space for an object of a specified size whose
initial value is indeterminate. It All memory allocation functions accept an argument of type `size_t`
that specifies the number of bytes of memory to be allocated.

*Note: The returned value from it should be checked for error.*

Here's an example of dynamically allocated memory for an integer:
```c
int* p = malloc(sizeof(int));
```

### Without a type
Memory can be allocated and stored in `void` pointer without specifying it's type.
```c
void* p = malloc(size);
```

Before `void` type was introduced:
```c
char* p = malloc(size);
```

### Casting
It is often recommended to cast result of a memory allocation function call but isn't required.
```c
int* p = (int*)malloc(sizeof(int));
```

## aligned_alloc()
## calloc()
## realloc()
## reallocarray() (Not standard)
## alloca()
## free()
