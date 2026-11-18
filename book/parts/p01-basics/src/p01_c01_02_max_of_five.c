#include <stdio.h>

int main(void)
{
    int x, max;

    scanf("%d", &max);
    for (int i = 1; i < 5; i++) {
        scanf("%d", &x);
        if (x > max)
            max = x;
    }
    printf("max = %d\n", max);
    return 0;
}
