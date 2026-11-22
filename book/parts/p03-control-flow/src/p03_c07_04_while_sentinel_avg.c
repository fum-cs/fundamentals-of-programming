#include <stdio.h>

int main(void)
{
    int x, count = 0, sum = 0;

    while (scanf("%d", &x) == 1 && x != -1) {
        sum += x;
        count++;
    }

    if (count == 0) {
        printf("No scores entered\n");
    } else {
        printf("count = %d, sum = %d, average = %.2f\n",
               count, sum, (double)sum / count);
    }

    return 0;
}
