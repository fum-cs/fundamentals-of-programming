#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("How many students? ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *a = malloc(n * sizeof(int));
    if (a == NULL) {
        printf("out of memory!\n");
        return 1;
    }

    long sum = 0;
    for (int i = 0; i < n; i++) {
        printf("score[%d] = ", i);
        scanf("%d", &a[i]);
        sum += a[i];
    }
    printf("sum = %ld, average = %.2f\n", sum, (double)sum / n);

    free(a);
    return 0;
}
