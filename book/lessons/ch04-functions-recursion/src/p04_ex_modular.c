#include <stdio.h>

typedef unsigned long long ull;

/* a^n mod m, assuming m < 2^32 so that every product fits in 64 bits */
ull mod_power(ull a, ull n, ull m)            /* iterative */
{
    ull res = 1 % m;
    a %= m;
    while (n) {
        if (n & 1) res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

ull mod_power_rec(ull a, ull n, ull m)        /* recursive */
{
    if (n == 0) return 1 % m;
    ull half = mod_power_rec(a, n / 2, m);
    ull r = half * half % m;
    return n % 2 == 1 ? r * (a % m) % m : r;
}

int main(void)
{
    printf("2^10 mod 1000         = %llu\n", mod_power(2, 10, 1000));
    printf("3^200 mod 1000000007  = %llu / %llu\n",
           mod_power(3, 200, 1000000007ULL), mod_power_rec(3, 200, 1000000007ULL));
    printf("7^(10^18) mod 1000003 = %llu / %llu\n",
           mod_power(7, 1000000000000000000ULL, 1000003ULL),
           mod_power_rec(7, 1000000000000000000ULL, 1000003ULL));
    return 0;
}
