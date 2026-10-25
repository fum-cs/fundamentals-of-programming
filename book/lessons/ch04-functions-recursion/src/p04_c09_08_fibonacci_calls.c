
#include <stdio.h>

static unsigned long calls = 0;       /* شمارندهٔ مشترک بین همهٔ فراخوانی‌ها */

unsigned long fib(int n)
{
    calls++;
    return (n < 2) ? (unsigned long)n : fib(n - 1) + fib(n - 2);
}

int main(void)
{
    int tests[] = {10, 20, 30};

    for (int i = 0; i < 3; i++) {
        calls = 0;
        unsigned long value = fib(tests[i]);
        printf("fib(%2d) = %7lu   calls = %lu\n", tests[i], value, calls);
    }
    return 0;
}
