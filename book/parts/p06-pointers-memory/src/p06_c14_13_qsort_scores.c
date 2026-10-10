#include <stdio.h>
#include <stdlib.h>

int by_score_desc(const void *x, const void *y)
{
    int a = *(const int *)x;
    int b = *(const int *)y;
    return (a < b) - (a > b);
}

int main(void)
{
    int scores[] = {18, 15, 20, 12, 17};
    int n = sizeof(scores) / sizeof(scores[0]);

    qsort(scores, n, sizeof(int), by_score_desc);

    for (int i = 0; i < n; i++)
        printf("%d ", scores[i]);
    printf("\n");
    return 0;
}
