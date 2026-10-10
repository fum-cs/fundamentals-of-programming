#include <stdio.h>
#include <stdlib.h>

int *make_range(int n)
{
    int *a = malloc(n * sizeof(int));
    if (a == NULL) return NULL;
    for (int i = 0; i < n; i++) a[i] = i;
    return a;
}

int main(void)
{
    int *r = make_range(5);
    if (r == NULL) return 1;
    for (int i = 0; i < 5; i++) printf("%d ", r[i]);
    printf("\n");
    free(r);
    return 0;
}
