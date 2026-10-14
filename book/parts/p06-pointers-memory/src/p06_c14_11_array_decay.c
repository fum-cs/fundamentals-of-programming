#include <stdio.h>

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};

    printf("a == &a[0]     : %d\n", a == &a[0]);
    printf("sizeof(a)      : %zu\n", sizeof(a));
    printf("sizeof(a + 0)  : %zu\n", sizeof(a + 0));
    printf("step of a + 1  : %ld bytes\n", (long)((char *)(a + 1) - (char *)a));
    printf("step of &a + 1 : %ld bytes\n", (long)((char *)(&a + 1) - (char *)&a));
    return 0;
}
