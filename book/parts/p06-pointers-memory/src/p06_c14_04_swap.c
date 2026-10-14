#include <stdio.h>

void swap_wrong(int a, int b)
{
    int t = a; a = b; b = t;
}

void swap(int *a, int *b)
{
    int t = *a; *a = *b; *b = t;
}

int main(void)
{
    int x = 3, y = 7;

    swap_wrong(x, y);
    printf("after swap_wrong: x=%d y=%d\n", x, y);

    swap(&x, &y);
    printf("after swap      : x=%d y=%d\n", x, y);
    return 0;
}
