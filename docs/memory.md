# Computer Memory
## Memory Layout
**Memory Layout of a Program:**
```plaintext
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓  ← High memory address
┃           Stack           ┃  ← Growing Downward ↓
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃                           ┃
┃        Free Space         ┃  ← Dynamic area that grows or shrinks
┃                           ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃           Heap            ┃  ← Growing Upward ↑
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃        BSS Segment        ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃       Data Segment        ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃       Text Segment        ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  ← Low memory address
```

- **Text Segment:** Contains the compiled program code (instructions). It's typically read-only to prevent accidental modification.

- **Data Segment:** Stores global and static variables that are explicitly initialized in the code.

- **BSS Segment:** Holds global and static variables that are uninitialized or initialized to zero.

- **Heap:** Used for dynamically allocated memory (e.g., memory allocated with `malloc` in C). Grows upward as needed.

- **Free Space:** The area between the heap and stack, allowing each to grow as required.

- **Stack:** Stores local variables, function call information (stack frames), and grows downward from high to low addresses.

### Stack
**Simplified Diagram:**
```plaintext
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓  ← High memory address
┃         Frame 1           ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃         Frame 2           ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃      Current Frame        ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫  (Grows downward ↓)
┃       Stack Pointer       ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃                           ┃
┃        Free Space         ┃
┃                           ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  ← Low memory address
```

**Detailed Diagram:**
```plaintext
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓  ← High memory address
┃       Frame Pointer       ┃  ←┐ ↳ Pointer to frame 1
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫   │
┃      Local Variables      ┃   │
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫   │ ↳ Frame 2
┃         Arguments         ┃   │
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫   │
┃      Return Address       ┃  ←┘
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃       Frame Pointer       ┃  ←┐ ↳ Pointer to frame 2
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫   │
┃      Local Variables      ┃   │
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫   │ ↳ Current frame
┃         Arguments         ┃   │
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫   │
┃      Return Address       ┃  ←┘
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃       Stack Pointer       ┃  ← Points to top of the stack (Frame)
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃                           ┃
┃        Free Space         ┃
┃                           ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  ← Low memory address
```

- **Previous Function Frame:** Contains the stack frame of the function that called the current function.

- **Return Address:** The memory address where execution should return after the function finishes.

- **Saved Frame Pointer:** A pointer to the base of the previous function’s frame, allowing access to its local variables.

- **Function Parameters:** Arguments passed into the current function from the calling function.

- **Local Variables:** Variables defined within the function, allocated space for their values.

- **Temporaries:** Space for temporary values or intermediate calculations used during function execution.

- **Free Space:** Area that can be used by either the stack or the heap, depending on allocation needs.

- **Stack Pointer:** A pointer that indicates the current top of the stack, changing as frames are pushed or popped.

**A Program in C That Uses Call-Stack:**
```c
 1. #include <stdio.h>
 2.
 3. int f1(int a, int b) {
 4.     a = a + 2;
 5.     b = b * 2;
 6.
 7.     return (a + b);
 8. }
 9.
10. int f2(void) {
11.     int x = 1;
12.     int y = 2;
13.
14.     return f1(x, y);
15. }
16.
17. int main(void) {
18.     int n = f2();
19.
20.     printf("%d\n", n);
21.
22.     return 0;
23. }
```

- **Frame 1:** `main()` function.
- **Frame 2:** `f1()` function.
- **Frame 3 / Current Frame:** `f2()` function (called from `f1()`).
- **Stack Pointer:** Always points to the current frame.
- **Frame Pointer:** Always points to base of it's previous frame.

#### Call-Stack
