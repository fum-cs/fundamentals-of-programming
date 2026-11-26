#include <stdio.h>

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Please enter a non-negative integer\n");
        return 1;
    }

    int original = n;
    int sum = 0, count = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
        count++;
    }

    printf("%d: digit sum = %d, digit count = %d\n", original, sum, count);
    return 0;
}
