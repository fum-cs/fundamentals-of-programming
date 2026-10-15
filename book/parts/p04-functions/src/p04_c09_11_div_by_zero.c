
#include <stdio.h>
#define uint    unsigned int

uint inc(uint a){ return ++a; }
uint dec(uint a){ return --a; }
uint sub(uint a, uint b){ return b == 0 ? a : sub(dec(a), dec(b)); }
uint div(uint a, uint b){ return a < b ? 0 : inc(div(sub(a, b), b)); }

int main(void){
    printf("div(23, 4) = %u\n", div(23, 4));
    printf("about to compute div(5, 0) ...\n");
    fflush(stdout);
    printf("div(5, 0)  = %u\n", div(5, 0));      /* هرگز به پایه نمی‌رسد */
    return 0;
}
