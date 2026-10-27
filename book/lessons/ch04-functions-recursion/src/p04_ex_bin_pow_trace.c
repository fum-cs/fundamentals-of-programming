#include <stdio.h>

typedef long long ll;
const ll MOD = 1000000007LL;

ll bin_pow(ll n, ll e)
{
    ll res = 1;
    while (e) {
        printf("res = %lld\n", res);
        if (e & 1) res = (res * n) % MOD;
        n = (n * n) % MOD;
        e >>= 1;
    }
    return res;
}

int main(void)
{
    printf("bin_pow(2, 10) = %lld\n", bin_pow(2, 10));
    return 0;
}
