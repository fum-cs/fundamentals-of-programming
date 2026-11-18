#include <stdio.h>

int main(void)
{
    double a = 0.1, b = 0.2;

    printf("%.17g\n", a + b);
    printf("equal to 0.3? %d\n", a + b == 0.3);
    return 0;
}
