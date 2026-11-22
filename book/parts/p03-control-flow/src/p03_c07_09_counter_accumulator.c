#include <stdio.h>

int main(void)
{
    int count = 0;
    int sum = 0;

    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            count++;
            sum += i;
        }
    }

    printf("count = %d, sum = %d\n", count, sum);
    return 0;
}
