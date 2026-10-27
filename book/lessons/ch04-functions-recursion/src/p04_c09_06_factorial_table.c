#include <stdio.h>

unsigned long long fact(unsigned n)
{
    return (n <= 1) ? 1ULL : n * fact(n - 1);
}

int main(void)
{
    for (unsigned n = 18; n <= 22; n++) {
        printf("%2u! = %llu\n", n, fact(n));
    }
    return 0;
}