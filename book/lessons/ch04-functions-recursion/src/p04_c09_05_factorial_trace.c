#include <stdio.h>

static int depth = 0;                 /* only used for indentation */

unsigned long long fact(unsigned n)   /* fact : N -> N */
{
    printf("%*s-> fact(%u)\n", depth * 3, "", n);
    depth++;

    unsigned long long r = (n <= 1) ? 1ULL : n * fact(n - 1);

    depth--;
    printf("%*s<- fact(%u) = %llu\n", depth * 3, "", n, r);
    return r;
}

int main(void)
{
    fact(4);
    return 0;
}