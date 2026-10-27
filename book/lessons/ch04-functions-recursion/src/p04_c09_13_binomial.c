#include <stdio.h>

static unsigned long calls;

/* algorithm 1: recursive, straight from Pascal's rule */
unsigned long long binom(int n, int k)
{
    calls++;
    return (k == 0 || k == n) ? 1ULL : binom(n - 1, k - 1) + binom(n - 1, k);
}

/* algorithm 2: a loop, same function */
unsigned long long binom_loop(int n, int k)
{
    unsigned long long r = 1;
    for (int i = 0; i < k; i++) {
        r = r * (n - i) / (i + 1);
    }
    return r;
}

int main(void)
{
    printf("Pascal's triangle:\n");
    for (int n = 0; n <= 6; n++) {
        for (int k = 0; k <= n; k++) {
            printf("%llu ", binom(n, k));
        }
        printf("\n");
    }

    printf("\n  (n,k)     value     calls   loop-version\n");
    int tests[][2] = { {5, 2}, {10, 5}, {20, 10}, {25, 12} };
    for (int i = 0; i < 4; i++) {
        int n = tests[i][0], k = tests[i][1];
        calls = 0;
        unsigned long long v = binom(n, k);
        printf("(%2d,%2d)  %8llu  %8lu   %llu\n", n, k, v, calls, binom_loop(n, k));
    }
    return 0;
}