#include <stdio.h>

int main(void)
{
    int tests[] = {1, 6, 7, 27};

    for (int t = 0; t < 4; t++) {
        unsigned long long n = tests[t];
        int steps = 0;

        while (n != 1) {                      /* repetition */
            if (n % 2 == 0) n = n / 2;        /* selection  */
            else            n = 3 * n + 1;
            steps++;                          /* sequence   */
        }
        printf("s(%2d) = %d steps\n", tests[t], steps);
    }
    return 0;
}