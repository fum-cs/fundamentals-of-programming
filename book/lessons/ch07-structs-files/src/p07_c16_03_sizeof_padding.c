#include <stdio.h>

struct X { char a; int b; char c; };
struct Y { int b; char a; char c; };

int main(void)
{
    printf("sum of fields : %zu\n", sizeof(char) + sizeof(int) + sizeof(char));
    printf("struct X      : %zu\n", sizeof(struct X));
    printf("struct Y      : %zu\n", sizeof(struct Y));
    return 0;
}
