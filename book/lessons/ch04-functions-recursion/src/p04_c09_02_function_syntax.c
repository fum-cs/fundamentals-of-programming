#include <stdio.h>

/* prototypes: declare the signatures */
unsigned square(unsigned x);         /* square  : N -> N        */
unsigned add_one(unsigned x);        /* add_one : N -> N        */
int      max2(int a, int b);         /* max2    : Z x Z -> Z    */
void     print_line(void);           /* no result (side effect) */

int main(void)
{
    printf("square(7)         = %u\n", square(7));
    printf("max2(-3, 8)       = %d\n", max2(-3, 8));
    printf("square(add_one(4)) = %u\n", square(add_one(4)));  /* composition: square o add_one */
    print_line();
    return 0;
}

unsigned square(unsigned x)  { return x * x; }
unsigned add_one(unsigned x) { return x + 1; }
int      max2(int a, int b)  { if (a > b) return a; return b; }
void     print_line(void)    { printf("--------------------\n"); }