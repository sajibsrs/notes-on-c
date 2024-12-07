# Recursion

## Basic Recursion
Recursion is when a function calls itself to solve smaller parts of a problem. This process continues until it reaches a base case, which is the simplest form of the problem that the function can solve directly without calling itself.

**Factorial of n**:
```c
int fact(int n) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}
```

## Tail Recursion
A tail recursive function is a special type of recursive function where the recursive call is the last operation performed before returning the result.

```c
int facttail(int n, int a) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else if (n == 1) {
        return a;
    } else {
        return facttail(n - 1, n * a);
    }
}
```
