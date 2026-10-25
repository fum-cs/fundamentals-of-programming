
#include <stdio.h>

#define SQUARE_BAD(x)  x * x
#define SQUARE(x)      ((x) * (x))
#define DOUBLE_BAD(x)  x + x
#define DOUBLE(x)      ((x) + (x))
#define MAX(a, b)      ((a) > (b) ? (a) : (b))

static int counter = 0;

int next(void)                         /* هر بار صدا زده شود، شمارنده را زیاد می‌کند */
{
    counter++;
    printf("   next() called -> %d\n", counter);
    return counter;
}

int max_fn(int a, int b) { return a > b ? a : b; }     /* نسخهٔ تابع واقعی */

int main(void)
{
    printf("SQUARE_BAD(3 + 1)  = %d\n", SQUARE_BAD(3 + 1));
    printf("SQUARE(3 + 1)      = %d\n", SQUARE(3 + 1));
    printf("3 * DOUBLE_BAD(2)  = %d\n", 3 * DOUBLE_BAD(2));
    printf("3 * DOUBLE(2)      = %d\n", 3 * DOUBLE(2));

    printf("\nMAX macro: MAX(next(), 0)\n");
    int m1 = MAX(next(), 0);
    printf("   result = %d\n", m1);

    counter = 0;
    printf("max_fn function: max_fn(next(), 0)\n");
    int m2 = max_fn(next(), 0);
    printf("   result = %d\n", m2);
    return 0;
}
