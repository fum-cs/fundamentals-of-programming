#include <stdio.h>

int a, b, result;            /* shared memory: inputs and outputs of the procedure */

void add_proc(void)          /* procedure: no parameters, no return value */
{
    result = a + b;
}

int main(void)
{
    a = 3; b = 4;
    add_proc();
    printf("3 + 4  = %d\n", result);

    a = 10; b = 25;
    add_proc();
    printf("10 + 25 = %d\n", result);

    return 0;
}