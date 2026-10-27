#include <stdio.h>

int main(void)
{
    int    i[2];
    double d[2];
    char   c[2];

    int    *pi = i;
    double *pd = d;
    char   *pc = c;

    printf("int    step: %ld bytes\n", (long)((char *)(pi + 1) - (char *)pi));
    printf("double step: %ld bytes\n", (long)((char *)(pd + 1) - (char *)pd));
    printf("char   step: %ld bytes\n", (long)((char *)(pc + 1) - (char *)pc));
    return 0;
}
