#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        printf("out of memory!\n");
        return 1;
    }

    *p = 2026;
    printf("*p = %d\n", *p);

    free(p);
    p = NULL;
    return 0;
}
