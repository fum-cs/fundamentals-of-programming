#include <stdio.h>

union Value {
    int i;
    float f;
};

int main(void)
{
    union Value v;

    v.f = 1.0f;
    printf("as float: %.1f\n", v.f);
    printf("as int  : 0x%08x\n", (unsigned int)v.i);
    printf("sizeof(union Value) = %zu\n", sizeof(union Value));
    return 0;
}
