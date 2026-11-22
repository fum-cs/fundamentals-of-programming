#include <stdio.h>

int main(void)
{
    int a = 12, b = 20;

    int max  = (a > b) ? a : b;
    int diff = (a > b) ? (a - b) : (b - a);                 /* |a - b| */
    int sign = (a - b > 0) ? 1 : ((a - b < 0) ? -1 : 0);

    printf("max = %d, |a - b| = %d, sign = %d\n", max, diff, sign);
    printf("a is %s\n", (a % 2 == 0) ? "even" : "odd");

    for (int n = 0; n <= 2; n++) {      /* a for loop: see chapter 7 */
        printf("%d file%s\n", n, (n == 1) ? "" : "s");
    }

    return 0;
}
