#include <stdio.h>

int main(void)
{
    /* first number greater than 100 that is divisible by both 7 and 11 */
    int found = -1;
    for (int i = 101; i <= 1000; i++) {
        if (i % 7 == 0 && i % 11 == 0) {
            found = i;
            break;
        }
    }
    printf("first match = %d\n", found);

    /* break leaves only the INNER loop */
    printf("pairs:");
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == 2) {
                break;
            }
            printf(" (%d,%d)", i, j);
        }
    }
    printf("\n");

    return 0;
}
