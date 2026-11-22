#include <stdio.h>

int main(void)
{
    int n = 1000;

    int linear = 0;
    for (int i = 0; i < n; i++) {
        linear++;
    }

    int halving = 0;
    for (int m = n; m > 1; m /= 2) {
        halving++;
    }

    long long quadratic = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            quadratic++;
        }
    }

    printf("n = %d\n", n);
    printf("single loop      : %d iterations\n", linear);
    printf("halving loop     : %d iterations\n", halving);
    printf("two nested loops : %lld iterations\n", quadratic);

    return 0;
}
