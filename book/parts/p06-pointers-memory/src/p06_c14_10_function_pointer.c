#include <stdio.h>

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

int apply(int (*op)(int, int), int a, int b)
{
    return op(a, b);
}

int main(void)
{
    printf("add: %d\n", apply(add, 6, 7));
    printf("mul: %d\n", apply(mul, 6, 7));
    return 0;
}
