# Computer Memory
## Random Access Memory (RAM)
```txt
+---------------------------+  <- High memory address
|            Stack          |  <- Growing Downward ↓
+---------------------------+
|                           |
|         Free Space        |  <- Dynamic area that grows or shrinks
|                           |
+---------------------------+
|            Heap           |  <- Growing Upward ↑
+---------------------------+
|         BSS Segment       |
+---------------------------+
|        Data Segment       |
+---------------------------+
|        Text Segment       |
+---------------------------+  <- Low memory address
```

- **Text Segment:** Contains the compiled program code (instructions). It's typically read-only to prevent accidental modification.

- **Data Segment:** Stores global and static variables that are explicitly initialized in the code.

- **BSS Segment:** Holds global and static variables that are uninitialized or initialized to zero.

- **Heap:** Used for dynamically allocated memory (e.g., memory allocated with malloc in C). Grows upward as needed.

- **Free Space:** The area between the heap and stack, allowing each to grow as required.

- **Stack:** Stores local variables, function call information (stack frames), and grows downward from high to low addresses.

### Stack
```txt
+--------------------------+  <- High memory address
|    Saved Frame Pointer   |  <-+--> Frame pointer
+--------------------------+    |
|      Local Variables     |    |
+--------------------------+    |--> Previous frame
|         Arguments        |    |
+--------------------------+    |
|      Return address      |  <-+
+--------------------------+
|    Saved Frame Pointer   |  <-+--> Frame pointer
+--------------------------+    |
|      Local Variables     |    |
+--------------------------+    |--> Current frame
|         Arguments        |    |
+--------------------------+    |
|      Return address      |  <-+
+--------------------------+
|      Stack Pointer       |  <- Stack pointer
+--------------------------+
|                          |
|        Free Space        |
|                          |
+--------------------------+  <- Low memory address
```

- **Previous Function Frame:** Contains the stack frame of the function that called the current function.

- **Return Address:** The memory address where execution should return after the function finishes.

- **Saved Frame Pointer:** A pointer to the base of the previous function’s frame, allowing access to its local variables.

- **Function Parameters:** Arguments passed into the current function from the calling function.

- **Local Variables:** Variables defined within the function, allocated space for their values.

- **Temporaries:** Space for temporary values or intermediate calculations used during function execution.

- **Free Space:** Area that can be used by either the stack or the heap, depending on allocation needs.

- **Stack Pointer:** A pointer that indicates the current top of the stack, changing as frames are pushed or popped.

