#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int cap = 2, size = 0;
    int *a = malloc(cap * sizeof(int));
    if (a == NULL) return 1;

    for (int v = 1; v <= 10; v++) {
        if (size == cap) {                       /* full: double it */
            int *tmp = realloc(a, 2 * cap * sizeof(int));
            if (tmp == NULL) {                   /* keep old block on failure */
                free(a);
                return 1;
            }
            a = tmp;
            cap *= 2;
            printf("grew to capacity %d\n", cap);
        }
        a[size++] = v * v;
    }

    for (int i = 0; i < size; i++) printf("%d ", a[i]);
    printf("\n");

    free(a);
    return 0;
}
