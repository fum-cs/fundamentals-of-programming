#include <stdio.h>

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;                 /* same as &a[0] */

    printf("a[2]     = %d\n", a[2]);
    printf("*(a + 2) = %d\n", *(a + 2));
    printf("*(p + 2) = %d\n", *(p + 2));
    printf("p[2]     = %d\n", p[2]);

    for (int *q = a; q < a + 5; q++)
        printf("%d ", *q);
    printf("\n");
    return 0;
}
