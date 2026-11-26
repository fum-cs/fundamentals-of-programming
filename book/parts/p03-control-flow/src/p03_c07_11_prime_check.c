#include <stdio.h>

int main(void)
{
    int n;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    if (n < 2) {
        printf("%d: not prime (must be at least 2)\n", n);
        return 0;
    }

    /* Version 1: try every d from 2 to n-1 */
    int prime_slow = 1, steps_slow = 0;
    for (int d = 2; d < n; d++) {
        steps_slow++;
        if (n % d == 0) {
            prime_slow = 0;
            break;
        }
    }

    /* Version 2: try d only while d*d <= n */
    int prime_fast = 1, steps_fast = 0;
    for (int d = 2; (long long)d * d <= n; d++) {
        steps_fast++;
        if (n % d == 0) {
            prime_fast = 0;
            break;
        }
    }

    printf("%d: %s | steps: slow = %d, fast = %d%s\n", n,
           prime_fast ? "prime" : "not prime", steps_slow, steps_fast,
           prime_slow != prime_fast ? "  MISMATCH!" : "");
    return 0;
}
