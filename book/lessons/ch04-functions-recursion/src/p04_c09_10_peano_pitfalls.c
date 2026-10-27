#include <stdio.h>
typedef unsigned int uint;

uint inc(uint a){ return ++a; }
uint dec(uint a){ return --a; }
uint sub(uint a, uint b){ return b == 0 ? a : sub(dec(a), dec(b)); }

/* natural subtraction (monus): never goes below zero */
uint monus(uint a, uint b){ return a < b ? 0 : sub(a, b); }

int main(void){
    printf("dec(0)             = %u\n", dec(0));
    printf("inc(4294967295)    = %u\n", inc(4294967295u));
    printf("sub(3, 5)          = %u   (3 - 5 mod 2^32)\n", sub(3, 5));
    printf("monus(3, 5)        = %u\n", monus(3, 5));
    return 0;
}