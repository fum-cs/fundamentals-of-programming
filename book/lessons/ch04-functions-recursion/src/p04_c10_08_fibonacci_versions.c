#include <stdio.h>

typedef long long ll;
const ll MOD = 1000000007LL;          /* results are taken modulo 10^9 + 7 */

static unsigned long calls;           /* counts the calls of the recursive versions */

/* version 1: straight from the definition */
ll fib_naive(ll n)
{
    calls++;
    return n < 2 ? n : (fib_naive(n - 1) + fib_naive(n - 2)) % MOD;
}

/* version 2: a loop that keeps the last two values */
ll fib_loop(ll n)
{
    ll a = 0, b = 1;                  /* F(0), F(1) */
    for (ll i = 0; i < n; i++) {
        ll c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return a;
}

/* version 3: halve n, but ask for F(k) and F(k-1) with two separate calls */
ll fib_two_calls(ll n)
{
    calls++;
    if (n < 2) return n;

    ll k = n / 2;
    ll f_k   = fib_two_calls(k);
    ll f_km1 = fib_two_calls(k - 1);
    ll f_kp1 = (f_k + f_km1) % MOD;

    if (n % 2 == 0)                                        /* n = 2k   */
        return ((f_kp1 * f_k) % MOD + (f_k * f_km1) % MOD) % MOD;
    return ((f_kp1 * f_kp1) % MOD + (f_k * f_k) % MOD) % MOD;  /* n = 2k+1 */
}

/* version 4: ONE call returns F(n); F(n+1) is left in the global fib_next */
static ll fib_next;

ll fib_fast(ll n)
{
    calls++;
    if (n == 0) { fib_next = 1; return 0; }      /* (F(0), F(1)) = (0, 1) */
    if (n == 1) { fib_next = 1; return 1; }      /* (F(1), F(2)) = (1, 1) */

    ll f_km1 = fib_fast((n >> 1) - 1);           /* n >> 1 is n / 2; k = n / 2 */
    ll f_k   = fib_next;                         /* F(k) comes with the call   */
    ll f_kp1 = (f_k + f_km1) % MOD;              /* F(k+1) */
    ll f_kp2 = (f_kp1 + f_k) % MOD;              /* F(k+2) */

    ll f_2k   = ((f_kp1 * f_k) % MOD + (f_k * f_km1) % MOD) % MOD;
    ll f_2kp1 = ((f_kp1 * f_kp1) % MOD + (f_k * f_k) % MOD) % MOD;
    ll f_2kp2 = ((f_kp1 * f_kp2) % MOD + (f_k * f_kp1) % MOD) % MOD;

    if (n & 1) {                                 /* n & 1 is n % 2: n = 2k+1 */
        fib_next = f_2kp2;                       /* F(n+1) = F(2k+2) */
        return f_2kp1;                           /* F(n)   = F(2k+1) */
    }
    fib_next = f_2kp1;                           /* n = 2k: F(n+1) = F(2k+1) */
    return f_2k;                                 /*         F(n)   = F(2k)   */
}

int main(void)
{
    int same = 1;
    for (ll n = 0; n <= 30; n++) {
        ll x = fib_loop(n);
        if (fib_naive(n) != x || fib_two_calls(n) != x || fib_fast(n) != x) same = 0;
    }
    printf("all four versions agree for n = 0..30 ? %s\n\n", same ? "yes" : "NO");

    printf("  n     naive calls   two-calls calls   fast calls\n");
    ll tests[] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        ll n = tests[i];
        unsigned long c1, c2, c3;
        calls = 0; fib_naive(n);      c1 = calls;
        calls = 0; fib_two_calls(n);  c2 = calls;
        calls = 0; fib_fast(n);       c3 = calls;
        printf("%3lld  %12lu  %16lu  %11lu\n", n, c1, c2, c3);
    }

    ll big = 1000000;
    unsigned long c2, c3;
    calls = 0; ll r2 = fib_two_calls(big); c2 = calls;
    calls = 0; ll r3 = fib_fast(big);      c3 = calls;
    printf("\nn = %lld: loop = %lld, two-calls = %lld (%lu calls), fast = %lld (%lu calls)\n",
           big, fib_loop(big), r2, c2, r3, c3);

    big = 1000000000000000000LL;                 /* 10^18: a loop would need 10^18 steps */
    calls = 0;
    ll r = fib_fast(big);
    printf("n = 10^18: F(n) mod 1e9+7 = %lld (%lu calls)\n", r, calls);
    return 0;
}
