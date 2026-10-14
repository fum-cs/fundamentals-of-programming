
#include <stdio.h>

/* بازگشتی (دُم‌دار): gcd(a, 0) = a ;  gcd(a, b) = gcd(b, a mod b) */
unsigned gcd_rec(unsigned a, unsigned b)
{
    return b == 0 ? a : gcd_rec(b, a % b);
}

/* حلقه: پارامترها → متغیرهای حلقه */
unsigned gcd_loop(unsigned a, unsigned b)
{
    while (b != 0) {
        unsigned t = a % b;       /* مقدار جدید b */
        a = b;                    /* به‌روزرسانی هم‌زمان (a, b) ← (b, a mod b) */
        b = t;
    }
    return a;
}

int main(void)
{
    unsigned tests[][2] = { {48, 18}, {17, 5}, {100, 75}, {7, 0} };

    for (int i = 0; i < 4; i++) {
        unsigned a = tests[i][0], b = tests[i][1];
        printf("gcd(%3u, %3u): recursive = %2u   loop = %2u\n",
               a, b, gcd_rec(a, b), gcd_loop(a, b));
    }
    return 0;
}
