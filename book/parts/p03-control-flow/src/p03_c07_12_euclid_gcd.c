#include <stdio.h>

int main(void)
{
    int a, b;

    if (scanf("%d %d", &a, &b) != 2 || a < 0 || b < 0) {
        printf("Please enter two non-negative integers\n");
        return 1;
    }

    int x = a, y = b, steps = 0;
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
        steps++;
    }

    printf("gcd(%d, %d) = %d  (%d step(s))\n", a, b, x, steps);
    return 0;
}
