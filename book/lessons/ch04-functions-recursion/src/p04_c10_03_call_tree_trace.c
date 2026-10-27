#include <stdio.h>

static int depth = 0;

int fib(int n)
{
    printf("%*s-> fib(%d)\n", depth * 3, "", n);          /* enter: pre-order */
    depth++;

    int r = (n < 2) ? n : fib(n - 1) + fib(n - 2);

    depth--;
    printf("%*s<- fib(%d) = %d\n", depth * 3, "", n, r);  /* leave: post-order */
    return r;
}

int main(void)
{
    fib(4);
    return 0;
}