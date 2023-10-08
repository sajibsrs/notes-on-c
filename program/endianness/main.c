#include <stdio.h>

union {
    short s;
    char c[sizeof(short)];
} un;

int main()
{
    un.s = 0x0102;

    if (sizeof(short) == 2) {
        if (un.c[0] == 1 && un.c[1] == 2) {
            printf("little-endian\n");
        } else if (un.c[0] == 2 && un.c[1] == 1) {
            printf("big-endian\n");
        }
    }
    return 0;
}
