#include <stdio.h>

void show(int arr[])
{
    /* arr is really an int* here */
    printf("inside show : sizeof(arr) = %zu\n", sizeof(arr));
}

int main(void)
{
    int a[10];
    printf("inside main : sizeof(a)   = %zu\n", sizeof(a));
    show(a);
    return 0;
}
