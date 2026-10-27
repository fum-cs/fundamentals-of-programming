#include <stdio.h>

typedef long long ll;
const ll MOD = 1000000007LL;

static unsigned long calls;

/* version 1: n^e = n * n^(e-1) */
ll pow_slow(ll n, ll e)
{
    calls++;
    return e == 0 ? 1 : n * pow_slow(n, e - 1) % MOD;
}

/* version 2: halve e, but call the function twice -> no gain */
ll pow_twice(ll n, ll e)
{
    calls++;
    if (e == 0) return 1;
    ll r = pow_twice(n, e / 2) * pow_twice(n, e / 2) % MOD;
    return e % 2 == 1 ? r * n % MOD : r;
}

/* version 3: halve e and keep the result of the single call */
ll bin_pow_rec(ll n, ll e)
{
    calls++;
    if (e == 0) return 1;

    ll half = bin_pow_rec(n, e / 2);          /* n^(e/2) */
    ll r = half * half % MOD;
    return e % 2 == 1 ? r * n % MOD : r;
}

int main(void)
{
    printf("     e   slow calls   twice calls   rec calls   3^e mod 1e9+7\n");
    ll tests[] = {5, 10, 20, 40, 1000};
    for (int i = 0; i < 5; i++) {
        ll e = tests[i];
        unsigned long c1, c2, c3;
        calls = 0; ll v1 = pow_slow(3, e);     c1 = calls;
        calls = 0; ll v2 = pow_twice(3, e);    c2 = calls;
        calls = 0; ll v3 = bin_pow_rec(3, e);  c3 = calls;
        printf("%6lld  %11lu  %12lu  %10lu   %lld%s\n", e, c1, c2, c3, v3,
               (v1 == v3 && v2 == v3) ? "" : "  (MISMATCH!)");
    }

    calls = 0;
    ll r = bin_pow_rec(3, 1000000000000000000LL);
    printf("\n3^(10^18) mod 1e9+7 = %lld (%lu calls)\n", r, calls);
    return 0;
}
