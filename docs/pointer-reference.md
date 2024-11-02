# Pointer & Reference
## Pointer type
## Reference
## Pointer & value
## Pointer & array

## Pointer & function
Pointer can be used with function in C. It can be used to point to different functions with same signature. A pointer pointing to a function can be passed in a function as a parameter and used/called inside that function.

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
  printf("Result: %d\n", res);
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

These both assignment is identical & works the same:
```c
int (*fn_ptr)(int, int) = add;
int (*fn_ptr)(int, int) = &add;
```

## Pointer & struct
## Pointer to pointer
## Constant pointer
