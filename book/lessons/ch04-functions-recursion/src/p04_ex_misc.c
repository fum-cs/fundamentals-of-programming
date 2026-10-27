#include <stdio.h>

typedef unsigned int uint;
static unsigned long calls;

uint inc(uint a) { return ++a; }
uint dec(uint a) { return --a; }
uint inc2(uint a) { return inc(inc(a)); }

uint add(uint a, uint b) { calls++; return b == 0 ? a : add(inc(a), dec(b)); }
uint sub(uint a, uint b) { return b == 0 ? a : sub(dec(a), dec(b)); }
uint mod(uint a, uint b) { return a < b ? a : mod(sub(a, b), b); }
uint mul(uint a, uint b) { return b == 0 ? 0 : add(mul(a, dec(b)), a); }

uint add2(uint a, uint b) { return b == 0 ? a : add2(inc2(a), dec(b)); }   /* a + 2b */
uint gcd(uint a, uint b)  { return b == 0 ? a : gcd(b, mod(a, b)); }
uint power(uint a, uint b) { return b == 0 ? 1 : mul(power(a, dec(b)), a); }

/* add as a loop */
uint add_loop(uint a, uint b)
{
    while (b != 0) { a = inc(a); b = dec(b); }
    return a;
}

/* sum of digits, two ways */
unsigned digits_rec(unsigned n)  { return n < 10 ? n : n % 10 + digits_rec(n / 10); }
unsigned digits_loop(unsigned n)
{
    unsigned s = 0;
    while (n > 0) { s += n % 10; n /= 10; }
    return s;
}

int main(void)
{
    calls = 0;
    printf("add(2, 2) = %u, calls = %lu\n", add(2, 2), calls);
    printf("add2(5, 3) = %u\n", add2(5, 3));
    printf("gcd(48, 18) = %u\n", gcd(48, 18));
    printf("power(2, 5) = %u, power(0, 0) = %u\n", power(2, 5), power(0, 0));
    printf("add_loop(7, 5) = %u\n", add_loop(7, 5));
    printf("digits(9875) = %u %u\n", digits_rec(9875), digits_loop(9875));

    int best_n = 1, best_steps = 0;
    for (int n = 1; n <= 30; n++) {
        unsigned long long x = n;
        int steps = 0;
        while (x != 1) { x = (x % 2 == 0) ? x / 2 : 3 * x + 1; steps++; }
        if (steps > best_steps) { best_steps = steps; best_n = n; }
    }
    printf("longest Collatz run for n <= 30: n = %d, steps = %d\n", best_n, best_steps);
    return 0;
}
