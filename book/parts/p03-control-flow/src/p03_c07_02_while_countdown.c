#include <stdio.h>

int main(void)
{
    int n = 5;
    int sum = 0;

    while (n > 0) {
        printf("%d ", n);
        sum += n;
        n--;
    }
    printf("Liftoff! sum = %d\n", sum);

    return 0;
}
