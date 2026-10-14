#include <stdio.h>

void min_max(const int a[], int n, int *min, int *max)
{
    *min = *max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < *min) *min = a[i];
        if (a[i] > *max) *max = a[i];
    }
}

int main(void)
{
    int scores[] = {18, 15, 20, 12, 17};
    int lo, hi;
    min_max(scores, 5, &lo, &hi);
    printf("min = %d, max = %d\n", lo, hi);
    return 0;
}
