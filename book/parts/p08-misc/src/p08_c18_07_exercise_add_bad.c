#include <stdio.h>

#define ADD_BAD(a, b) a + b

int main(void)
{
    printf("%d\n", ADD_BAD(2, 3) * 4);
    return 0;
}
