
#include <stdio.h>

int main(void)
{
    int tests[] = {1, 6, 7, 27};

    for (int t = 0; t < 4; t++) {
        unsigned long long n = tests[t];
        int steps = 0;

        while (n != 1) {                      /* تکرار  */
            if (n % 2 == 0) n = n / 2;        /* انتخاب */
            else            n = 3 * n + 1;
            steps++;                          /* ترتیب  */
        }
        printf("s(%2d) = %d steps\n", tests[t], steps);
    }
    return 0;
}
