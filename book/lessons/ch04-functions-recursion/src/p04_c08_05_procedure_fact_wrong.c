
#include <stdio.h>

int  n;                      /* «ورودی» رویه */
long result;                 /* «خروجی» رویه */

void fact_proc(void)
{
    if (n <= 1) {
        result = 1;
        return;
    }
    n = n - 1;               /* می‌خواهیم برای n-1 حل کنیم ... */
    fact_proc();             /* ... پس خودمان را صدا می‌زنیم */
    result = result * n;     /* و حالا می‌خواهیم در n «اصلی» ضرب کنیم */
}

int main(void)
{
    n = 5;
    fact_proc();
    printf("5! = %ld (expected 120)\n", result);
    return 0;
}
