#include <stdio.h>

int main(void)
{
    int x = 10;
    int *p = &x;          /* p holds the address of x */

    printf("x  = %d\n", x);
    printf("*p = %d\n", *p);   /* read through the pointer */

    *p = 99;                   /* write through the pointer */
    printf("x  = %d\n", x);    /* x changed! */
    return 0;
}
