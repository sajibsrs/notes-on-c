#include <stdio.h>

int method(int num);
int point_method(int (*p_fn)(int), int num);

int main()
{
    int (*p_mt)(int) = method;
    int (*p_pmt)(int (*)(int), int) = point_method;

    printf("%d\n", p_pmt(p_mt, 10));

    return 0;
}

int method(int num)
{
    return num;
}

int point_method(int (*p_fn)(int), int num)
{
    int val = p_fn(num);
    return val * val;
}
