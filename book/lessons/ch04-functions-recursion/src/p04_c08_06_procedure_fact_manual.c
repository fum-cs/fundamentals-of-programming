#include <stdio.h>

int  n;
long result;

void fact_proc(void)
{
    if (n <= 1) {
        result = 1;
        return;
    }
    n = n - 1;
    fact_proc();
    n = n + 1;               /* restore the original n by hand */
    result = result * n;
}

int main(void)
{
    n = 5;
    fact_proc();
    printf("5! = %ld\n", result);
    return 0;
}