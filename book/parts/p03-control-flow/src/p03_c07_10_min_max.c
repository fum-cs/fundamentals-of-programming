#include <stdio.h>

int main(void)
{
    int x, min = 0, max = 0, count = 0;

    while (scanf("%d", &x) == 1) {
        if (count == 0) {
            min = x;
            max = x;
        } else {
            if (x < min) {
                min = x;
            }
            if (x > max) {
                max = x;
            }
        }
        count++;
    }

    if (count == 0) {
        printf("No data\n");
    } else {
        printf("count = %d, min = %d, max = %d\n", count, min, max);
    }

    return 0;
}
