#include <stdio.h>

int main(void)
{
    double x = 2.0;
    double g = x;                 /* initial guess */
    double eps = 1e-9;
    int steps = 0;

    double err = g * g - x;
    err = (err < 0) ? -err : err;          /* absolute value via ?: */

    while (err > eps && steps < 50) {      /* 50 = safety cap */
        g = (g + x / g) / 2.0;
        err = g * g - x;
        err = (err < 0) ? -err : err;
        steps++;
        printf("step %d: g = %.10f, error = %.3e\n", steps, g, err);
    }

    printf("sqrt(%.1f) ~ %.10f after %d step(s)\n", x, g, steps);
    return 0;
}
