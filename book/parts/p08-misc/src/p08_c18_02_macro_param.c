#include <stdio.h>

#define IS_PASSED(score, limit) ((score) >= (limit))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    int a = 14, b = 19;

    printf("MAX(a, b)     = %d\n", MAX(a, b));
    printf("MAX(a + 6, b) = %d\n", MAX(a + 6, b));
    printf("IS_PASSED(a, 12)     = %d\n", IS_PASSED(a, 12));
    printf("IS_PASSED(a - 3, 12) = %d\n", IS_PASSED(a - 3, 12));
    return 0;
}
