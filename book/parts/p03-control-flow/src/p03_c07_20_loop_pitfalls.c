#include <stdio.h>

int main(void)
{
    /* 1. off-by-one: < versus <= */
    int sum_lt = 0, sum_le = 0, it_lt = 0, it_le = 0;
    for (int i = 1; i < 10; i++)  { sum_lt += i; it_lt++; }
    for (int i = 1; i <= 10; i++) { sum_le += i; it_le++; }
    printf("1) i < 10  : %d iterations, sum = %d\n", it_lt, sum_lt);
    printf("   i <= 10 : %d iterations, sum = %d\n", it_le, sum_le);

    /* 2. unsigned counter: i >= 0 is always true (capped here at 5 iterations) */
    printf("2) unsigned countdown from 2:");
    int guard = 0;
    for (unsigned int u = 2; u >= 0 && guard < 5; u--, guard++) {
        printf(" %u", u);
    }
    printf("\n");

    /* 3. a stray semicolon turns the body into an empty statement */
    int count = 0;
    for (int i = 0; i < 5; i++);
    {
        count++;
    }
    printf("3) count = %d (expected 5)\n", count);

    return 0;
}
