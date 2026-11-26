#include <stdio.h>

int main(void)
{
    /* Danger: counting with a double and testing with != */
    double x = 0.0;
    int k = 0;
    while (x != 1.0 && k < 12) {     /* k < 12 is a safety cap for this demo */
        x += 0.1;
        k++;
    }
    printf("after %d additions: x = %.17f, x == 1.0 ? %d\n", k, x, x == 1.0);

    /* Safer: count with an integer, derive the double from it */
    int hits = 0;
    for (int j = 0; j <= 10; j++) {
        double y = j * 0.1;
        if (y == 1.0) {
            hits++;
        }
    }
    printf("integer counter: reached 1.0 exactly %d time(s)\n", hits);

    return 0;
}
