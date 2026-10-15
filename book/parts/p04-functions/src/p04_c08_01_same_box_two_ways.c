
#include <stdio.h>

int main(void)
{
    for (int n = 1; n <= 10; n += 3) {

        /* جعبه ۱: حلقه */
        int by_loop = 0;
        for (int i = 1; i <= n; i++) {
            by_loop += i;
        }

        /* جعبه ۲: فرمول */
        int by_formula = n * (n + 1) / 2;

        printf("n = %2d | loop = %2d | formula = %2d | same? %s\n",
               n, by_loop, by_formula, by_loop == by_formula ? "yes" : "no");
    }
    return 0;
}
