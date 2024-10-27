# Bitwise Operators in C

## AND (&)

## OR (|)

## NOT (~)

## XOR (^)

## SHIFT LEFT (<<)

## SHIFT RIGHT (>>)

### Bit Order / Bit significance
#### Most Significant Bit (MSB)
- The highest-order bit in a binary number, or the bit with the highest value position.
- It represents the largest possible value in the binary number.
- In an 8-bit number like 10011001, the leftmost bit (1) is the MSB.
- The MSB is sometimes referred to as the "sign bit" in signed binary representations, as it determines the sign (positive or negative) of the number in two's complement representation.

#### Least Significant Bit (LSB)
- The lowest-order bit in a binary number, or the bit with the smallest value position.
- It represents the smallest possible value in the binary number (either 0 or 1).
- In the number 10011001, the rightmost bit (1) is the LSB.
- The LSB is also sometimes called the "rightmost bit" or simply the "low bit."

### Byte Order / Endianness
#### Big Endian (BE)
#### Little Endian (LE)

## Memory Program
Here's a program to determine memory address, byte order and binary values stored in the memory.

```c
char* char_to_bin(char c) {
  char* arr = malloc(9); // 8 bits + 1 for the null terminator
  if (!arr) {
    return NULL;
  }

  for (int i = (sizeof(char) * 8) - 1; i >= 0; i--) {
    arr[7 - i] = ((c >> i) & 1) ? '1' : '0'; // bit-masking and string conversion
  }
  arr[8] = '\0';

  return arr;
}

int main() {
  int x = 1;
  char* px = (char*)&x;

  for (int i = 0; i < sizeof(int); i++) {
    char* binary = char_to_bin(*(px + i));
    printf("byte %d at: %p %s\n", i, (void*)(px + i), binary);

    free(binary);
  }

  return 0;
}
```

Output:
```txt
byte 0 at: 0x16b68af54 00000001
byte 1 at: 0x16b68af55 00000000
byte 2 at: 0x16b68af56 00000000
byte 3 at: 0x16b68af57 00000000
```
