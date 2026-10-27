#include <stdio.h>

#ifndef N
#define N 1000
#endif

unsigned long long sum_to(unsigned long long n)     /* sum_to(n) = 1 + 2 + ... + n */
{
    return (n == 0) ? 0 : n + sum_to(n - 1);
}

int main(void)
{
    printf("sum_to(%d) = %llu\n", N, sum_to(N));
    return 0;
}