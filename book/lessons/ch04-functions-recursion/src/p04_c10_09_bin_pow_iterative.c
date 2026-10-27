#include <stdio.h>

typedef long long ll;
const ll MOD = 1000000007LL;

/* n^e mod MOD: look at the bits of e from the lowest one */
ll bin_pow(ll n, ll e)
{
    ll res = 1;
    while (e) {
        printf("e = %2lld   n = %5lld   res = %lld\n", e, n, res);   /* trace */
        if (e & 1) res = (res * n) % MOD;     /* the lowest bit of e is 1: use n */
        n = (n * n) % MOD;                    /* n, n^2, n^4, n^8, ...           */
        e >>= 1;                              /* drop the lowest bit of e        */
    }
    return res;
}

int main(void)
{
    printf("3^13 = %lld\n", bin_pow(3, 13));  /* 13 = 1101 in binary */
    return 0;
}
