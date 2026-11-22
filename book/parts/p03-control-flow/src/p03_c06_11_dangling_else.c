#include <stdio.h>

int main(void)
{
    int a = 1, b = 0;

    /* looks like "else belongs to the outer if", but it does not */
    if (a == 1)
        if (b == 1)
            printf("both are 1\n");
    else
        printf("else: runs when a == 1 and b != 1\n");

    /* braces make the intention explicit */
    if (a == 1) {
        if (b == 1) {
            printf("both are 1\n");
        }
    } else {
        printf("a is not 1\n");
    }

    return 0;
}
