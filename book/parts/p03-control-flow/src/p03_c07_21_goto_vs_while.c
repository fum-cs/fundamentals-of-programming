#include <stdio.h>

int main(void)
{
    /* version 1: a loop built from goto */
    int i = 1, sum1 = 0;
loop:
    if (i > 5) {
        goto done;
    }
    sum1 += i;
    i++;
    goto loop;
done:
    printf("goto  version: sum = %d\n", sum1);

    /* version 2: the same loop with while */
    int sum2 = 0;
    int k = 1;
    while (k <= 5) {
        sum2 += k;
        k++;
    }
    printf("while version: sum = %d\n", sum2);

    return 0;
}
