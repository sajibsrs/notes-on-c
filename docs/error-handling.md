# Error Handling

## Condition
Some error can be handled with just a conditional statements.

```c
int main() {
  int a;
  int *p = malloc(sizeof(int));

  if (p == NULL) {
    printf("Allocation failed\n");
    return EXIT_FAILURE;
  }

  *p = 5;

  printf("a: %d\n", *p);
  free(p);

  return EXIT_SUCCESS;
}
```
`malloc` function returns `NULL` if it fails.
- `EXIT_FAILURE` or 1
- `EXIT_SUCCESS` or 0

*Basically the same thing.*

Success:
```plaintext
a: 5
```

Failure:
```plaintext
Allocation failed
with code: 1
```

## assert
`assert` macro can be used to check truthiness of a statement. If it's false, program exits early.

```c
int main() {
  int x = 2;
  int y = 3;

  assert(x == y);

  return 0;
}
```

Output:
```plaintext
Assertion failed: (x == y), function main, file main.c, line 9.
```
`assert` has performance penalty, thus it's mostly used for debugging. On the release version, it's simply can be disabled by `#define NDEBUG` right above `#include <assert.h>`.

```c
#define NDEBUG
#include <assert.h>
```

## errorno
`errno` works as a global variable (thread-local). So we need to set it to `0` first, to clear out any previous error.

For specific errors, errorno defines different error type. Which can be used to determine error type. Such as EDOM, ERANGE, EINTR, EIO etc.
```c
#include <errno.h>

int main() {
  errno = 0;
  double res = strtol("999999999999999999999", NULL, 10);

  if (errno != 0) {
    fprintf(stderr, "Operation error\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}
```

Output:
```plaintext
Operation error
```

### perror
`perror` actually prints the error message. It uses the current error code from `errorno`.
```c
#include <stdio.h>

if (errno != 0) {
  perror("Error");
  exit(EXIT_FAILURE);
}
```

Output:
```plaintext
Error: Result too large
```

### strerror
`strerror` returns the error message, it doesn't print by default, and errorno (error code) must be supplied to it explicitly.
```c
#include <string.h>

if (errno != 0) {
  puts(strerror(errno));
  exit(EXIT_FAILURE);
}
```

Output:
```plaintext
Result too large
```

**Warning!:** The `errno` variable is thread-local, meaning each thread has its own separate `errno` variable. However, in multi-threaded applications, care should still be taken to check `errno` immediately after a function that might set it. Failing to do so can lead to errors being missed or misinterpreted, as other functions might modify `errno` within the same thread before it is checked.


## Signal
Signal is actually, inter-process communication (IPC) mechanism designed to handle specific asynchronous events such as process interruptions, illegal instructions, segmentation faults, or termination requests, which can be used for error handling.

Function signature:
```c
void (*signal(int sig, void (*func)(int)))(int);
```
signal(signal, handler)

### Signal Type
The first parameter of signal function is the signal (signal type). A signal can be raised by the system, interrupts or others. We subscribe to that specific signal.

Some of the signals are:
- `SIGABRT` - Abnormal termination (Abort).
- `SIGFPE` - Error during an arithmetic operation.
- `SIGILL` - Invalid instruction.
- `SIGINT` - Interrupt.
- `SIGSEGV` - Invalid storage access.
- `SIGTERM` - Terminal request.

### Handler
A handler is the second parameter of the signal function. Which is responsible for what happens when this signal is encountered. There are some built in handler and we can define our own.

Default handler:
- `SIG_DFL` - Default signal handling.
- `SIG_IGN` - Signal is ignored.

Custom handler:
```c
void handler(int sig) {
  printf("%s\n", strsignal(sig));
  exit(EXIT_FAILURE);
}

int main() {
  signal(SIGINT, handler);
  raise(SIGINT);

  return 0;
}
```

Output:
```plaintext
Interrupt: 2
```

### raise
`raise` is used to manually raise a signal.

```c
raise(SIGINT);
```

## setjmp & longjmp
