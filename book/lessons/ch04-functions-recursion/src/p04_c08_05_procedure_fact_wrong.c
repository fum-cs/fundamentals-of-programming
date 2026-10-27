#include <stdio.h>

int  n;                      /* the procedure's "input" */
long result;                 /* the procedure's "output" */

void fact_proc(void)
{
    if (n <= 1) {
        result = 1;
        return;
    }
    n = n - 1;               /* we want to solve for n-1 ... */
    fact_proc();             /* ... so we call ourselves */
    result = result * n;     /* now we want to multiply by the ORIGINAL n */
}

int main(void)
{
    n = 5;
    fact_proc();
    printf("5! = %ld (expected 120)\n", result);
    return 0;
}