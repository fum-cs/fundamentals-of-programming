#include <stdio.h>

int main(void)
{
    int *p = NULL;
    if (p == NULL)
        printf("p points to nothing yet\n");

    int x = 8;
    p = &x;
    if (p != NULL)
        printf("now *p = %d\n", *p);
    return 0;
}
