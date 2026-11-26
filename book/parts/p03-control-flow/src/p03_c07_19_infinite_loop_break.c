#include <stdio.h>

int main(void)
{
    int x, total = 0;

    while (1) {
        if (scanf("%d", &x) != 1) {
            printf("input ended\n");
            break;
        }
        if (x == 0) {
            printf("zero received: stop\n");
            break;
        }
        total += x;
        printf("running total = %d\n", total);
    }

    printf("final total = %d\n", total);
    return 0;
}
