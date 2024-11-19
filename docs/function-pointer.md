# Function Pointers

## Function Pointer Nesting
### # Combination One
```c
#include <stdio.h>

/**
 * @brief A function that takes an int and returns void.
 * @param a An integer parameter.
 */
void fun1(int a) {
    printf("fun1 received: %d\n", a);
}

/**
 * @brief A function that takes an int and returns a function pointer.
 * @param a An integer parameter.
 * @return Pointer to a function that:
 *         - Takes an int.
 *         - Returns void.
 *
 * Signature of return function pointer: `void(*)(int)`
 */
void (*fun2(int a))(int) {
    printf("fun2 received: %d\n", a);
    return fun1;
}

/**
 * @brief A function that takes an int and returns a function pointer.
 *        The returned function pointer itself returns a function pointer.
 * @param a An integer parameter.
 * @return Pointer to a function that:
 *         - Takes an int.
 *         - Returns a pointer to a function that takes an int and returns void.
 *
 * Signature of return function pointer: `void(*(*)(int))(int)`
 */
void (*(*fun3(int a))(int))(int) {
    printf("fun3 received: %d\n", a);
    return fun2;
}

/**
 * @brief A function that takes an int and returns a function pointer.
 *        The returned function pointer itself returns a function pointer, which
 *        also returns another function pointer.
 * @param a An integer parameter.
 * @return Pointer to a function that:
 *         - Takes an int.
 *         - Returns a pointer to a function that:
 *           - Takes an int.
 *           - Returns a pointer to a function that takes an int and returns void.
 *
 * Signature of return function pointer: `void(*(*(*)(int))(int))(int)`
 */
void (*(*(*fun4(int a))(int))(int))(int) {
    printf("fun4 received: %d\n", a);
    return fun3;
}

int main(void) {
    /**
     * @brief A function pointer to `fun1`.
     * Signature: `void (*)(int)`
     */
    void (*fn1)(int) = fun1;

    /**
     * @brief A function pointer to the function returned by `fun2(1)`.
     * Signature: `void (*)(int)`
     */
    void (*fn2)(int) = fun2(1);

    /**
     * @brief A function pointer to the function returned by `fun3(2)`.
     * Signature: `void (*(*)(int))(int)`
     */
    void (*(*fn3)(int))(int) = fun3(2);

    /**
     * @brief A function pointer to the function returned by `fun4(3)`.
     * Signature: `void (*(*(*)(int))(int))(int)`
     */
    void (*(*(*fn4)(int))(int))(int) = fun4(3);

    fn1(4);
    fn2(5);
    fn3(6)(7);
    fn4(8)(9)(10);

    return 0;
}
```

### # Combination Two
```c
#include <stdio.h>

/**
 * @brief A function that takes an integer and prints it.
 * @param i The integer to be printed.
 */
void fnx(int i) {
    printf("fnx: %d\n", i);
}

/**
 * @brief A function that takes an integer and returns a function pointer.
 *        The returned function pointer has the signature `void (*)(int)`.
 * @param i An integer parameter.
 * @return A pointer to a function that:
 *         - Takes an integer.
 *         - Returns void.
 *
 * Signature of return function pointer: `void(*)(int)`
 */
void (*fun(int i))(int) {
    printf("fun: %d\n", i);
    return fnx;
}

/**
 * @brief A function that takes a function pointer as a parameter and returns a function pointer.
 *        The input function pointer has the signature `void (*)(int)`.
 *        The returned function pointer has the signature `void (*)(int)`.
 * @param pfn A function pointer with the signature `void (*)(int)`.
 * @return A pointer to a function that:
 *         - Takes an integer.
 *         - Returns void.
 *
 * Signature of return function pointer: `void(*)(int)`
 */
void (*fun1(void (*pfn)(int)))(int) {
    printf("fun1: ");
    pfn(4);
    return fnx;
}

/**
 * @brief A function that takes a function pointer as a parameter and returns a function pointer.
 *        The input function pointer takes another function pointer as input.
 *        The returned function pointer has the signature `void (*)(int)`.
 * @param pfn A function pointer with the signature `void (*pfn(void (*)(int)))(int)`.
 * @return A pointer to a function that:
 *         - Takes an integer.
 *         - Returns void.
 *
 * Signature of return function pointer: `void(*)(int)`
 */
void (*fun2(void (*pfn(void (*)(int)))(int)))(int) {
    printf("fun2:\n");
    pfn(fnx);
    return fnx;
}

int main(void) {
    /**
     * @brief A function pointer to `fnx`.
     * Signature: `void (*)(int)`
     */
    void (*fx)(int) = fnx;
    fx(1);  // Output: fnx: 1

    /**
     * @brief A function pointer to the function returned by `fun(2)`.
     * Signature: `void (*(*)(int))(int)`
     */
    void (*(*fn)(int))(int) = fun;
    fn(2)(3);  // Output: fun: 2, fnx: 3

    /**
     * @brief A function pointer to the function returned by `fun1(fnx)`.
     * Signature: `void (*(*)(void (*)(int)))(int)`
     */
    void (*(*fn1)(void (*)(int)))(int) = fun1;
    fn1(fnx)(5);  // Output: fun1: fnx: 4, fnx: 5

    /**
     * @brief A function pointer to the function returned by `fun2(fun1)`.
     * Signature: `void (*(*)(void (*pfn(void (*)(int)))(int)))(int)`
     */
    void (*(*fn2)(void (*pfn(void (*)(int)))(int)))(int) = fun2;
    fn2(fun1)(6);  // Output: fun2:, fun1: fnx: 4, fnx: 6

    return 0;
}
```
