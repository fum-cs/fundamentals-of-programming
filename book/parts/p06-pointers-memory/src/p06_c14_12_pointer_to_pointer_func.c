#include <stdio.h>

void set_to_larger(int **pp, int *x, int *y)
{
    *pp = (*x > *y) ? x : y;
}

int main(void)
{
    int a = 3, b = 9;
    int *best = NULL;

    set_to_larger(&best, &a, &b);
    printf("*best = %d\n", *best);
    return 0;
}
