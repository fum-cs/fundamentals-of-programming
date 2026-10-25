
#include <stdio.h>
#define uint    unsigned int

uint inc(uint a){ return ++a; }
uint dec(uint a){ return --a; }

uint add(uint a, uint b){ return b == 0 ? a : add(inc(a), dec(b)); }
uint sub(uint a, uint b){ return b == 0 ? a : sub(dec(a), dec(b)); }
uint mul(uint a, uint b){ return b == 0 ? 0 : add(mul(a, dec(b)), a); }
uint mod(uint a, uint b){ return a < b  ? a : mod(sub(a, b), b); }
uint div(uint a, uint b){ return a < b  ? 0 : inc(div(sub(a, b), b)); }

int main(void){
    printf("add(7, 5)   = %u\n", add(7, 5));
    printf("sub(7, 5)   = %u\n", sub(7, 5));
    printf("mul(7, 5)   = %u\n", mul(7, 5));
    printf("mod(23, 4)  = %u\n", mod(23, 4));
    printf("div(23, 4)  = %u\n", div(23, 4));
    return 0;
}
