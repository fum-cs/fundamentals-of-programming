#include <stdio.h>

/* not tail recursive: the addition happens AFTER the call returns */
unsigned digits_rec(unsigned n)
{
    return n < 10 ? n : n % 10 + digits_rec(n / 10);
}

/* tail recursive: the partial sum travels in the parameter acc */
unsigned digits_tail(unsigned n, unsigned acc)
{
    return n == 0 ? acc : digits_tail(n / 10, acc + n % 10);
}

unsigned digits_loop(unsigned n)
{
    unsigned acc = 0;
    while (n != 0) {
        acc = acc + n % 10;
        n = n / 10;
    }
    return acc;
}

int main(void)
{
    printf("%u %u %u\n", digits_rec(9875), digits_tail(9875, 0), digits_loop(9875));
    return 0;
}
