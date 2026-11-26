#include <stdio.h>

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }

    int original = n;
    int count = 0;

    do {
        count++;
        n /= 10;
    } while (n > 0);

    printf("%d has %d digit(s)\n", original, count);
    return 0;
}
