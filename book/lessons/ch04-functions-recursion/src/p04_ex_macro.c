#include <stdio.h>

#define MAX_BAD(a, b)  a > b ? a : b
#define MAX(a, b)      ((a) > (b) ? (a) : (b))
#define TWICE(x)       2 * x
#define CUBE_BAD(x)    x * x * x
#define CUBE(x)        ((x) * (x) * (x))

int main(void)
{
    printf("MAX_BAD(2, 1) + 10 = %d   (expected 12)\n", MAX_BAD(2, 1) + 10);
    printf("MAX(2, 1) + 10     = %d\n", MAX(2, 1) + 10);
    printf("TWICE(1 + 2)       = %d   (expected 6)\n", TWICE(1 + 2));
    printf("CUBE_BAD(1 + 2)    = %d   (expected 27)\n", CUBE_BAD(1 + 2));
    printf("CUBE(1 + 2)        = %d\n", CUBE(1 + 2));
    return 0;
}
