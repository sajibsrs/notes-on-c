# Macro
## User Defined Macro
## Preprocessor Directives
## Built-in Macros
## _Generic (c11)

```c
#include <stdio.h>

#define typeof(x)               \
    _Generic((x),               \
        char: "char",           \
        char *: "string",       \
        int: "int",             \
        float: "float",         \
        struct Vec2: "vec2",    \
        default: "unknown")

struct Vec2 {
    int x;
    int y;
};

int main(void) {
    struct Vec2 p = {4, 5};
    printf("Data type: %s\n", typeof(p));
    return 0;
}
```

Output:

```plaintext
Data type: vec2
```
