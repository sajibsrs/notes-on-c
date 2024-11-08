# Pointer & Reference
## Pointer type
## Reference
## Pointer & value
## Pointer & array

## Pointer & function
Pointer can be used with function in C. It can be used to point to different functions with same signature. A pointer pointing to a function can be passed in a function as a parameter and used/called inside that function.

### Function Pointer Assignment
```c
int add(int x) {
  return x + 5;
}

int main(void) {
  int (*fn)(int) = add;

  int x = fn(1);

  printf("x: %d\n", x);

  return 0;
}
```

These both assignments are identical & works the same:
```c
int (*fn)(int) = add;
int (*fn)(int) = &add;
```

Output:
```plaintext
x: 6
```

### Function Pointer as Parameter
Declaration:
```c
int add(int a, int b) {
  return a + b;
}

int subtract(int a, int b) {
  return a - b;
}

void apply(int x, int y, int (*op)(int, int)) {
  int res = op(x, y);
  printf("result: %d\n", res);
}
```

Usage:
```c
int main() {
  int (*fn_ptr)(int, int) = add;
  apply(3, 4, fn_ptr);

  fn_ptr = subtract;
  apply(5, 2, fn_ptr);

  return 0;
}
```

Output:
```plaintext
result: 7
result: 3
```

### Returning Function Pointer
```c
int add(int x) {
  return x + 5;
}

char (*to_char(int (*op)(int)))(char) {
  return (char (*)(char))op;
}

int main(void) {
  int (*fn)(int) = add;
  int x = fn(1);
  printf("x: %d\n", x);

  char (*fn_ptr)(char) = to_char(fn);
  char y = fn_ptr('A');
  printf("y: %c\n", y);

  return 0;
}
```

Output:
```plaintext
x: 6
y: F    // F is 5 character after A.
```

## Pointer & struct
## Pointer to pointer
## Constant pointer
