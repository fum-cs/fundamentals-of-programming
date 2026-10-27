#include <stdio.h>

int main(void)
{
    /* f(x) = (3x + 1) mod 7 on {0, ..., 6} */
    int injective = 1, surjective = 1;

    for (int x1 = 0; x1 < 7; x1++)
        for (int x2 = x1 + 1; x2 < 7; x2++)
            if ((3 * x1 + 1) % 7 == (3 * x2 + 1) % 7) injective = 0;

    for (int y = 0; y < 7; y++) {
        int reached = 0;
        for (int x = 0; x < 7; x++)
            if ((3 * x + 1) % 7 == y) reached = 1;
        if (!reached) surjective = 0;
    }

    printf("injective : %s\n", injective ? "yes" : "no");
    printf("surjective: %s\n", surjective ? "yes" : "no");
    printf("bijective : %s\n", (injective && surjective) ? "yes" : "no");
    return 0;
}
