#include <stdio.h>

int main(void)
{
    int a, b, c;

    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 1;
    }

    if (a <= 0 || b <= 0 || c <= 0) {
        printf("%d %d %d: invalid (sides must be positive)\n", a, b, c);
    } else if (a + b <= c || a + c <= b || b + c <= a) {
        printf("%d %d %d: not a triangle\n", a, b, c);
    } else {
        int right = (a * a + b * b == c * c) ||
                    (a * a + c * c == b * b) ||
                    (b * b + c * c == a * a);

        printf("%d %d %d: ", a, b, c);
        if (a == b && b == c) {
            printf("equilateral");
        } else if (a == b || b == c || a == c) {
            printf("isosceles");
        } else {
            printf("scalene");
        }
        if (right) {
            printf(", right-angled");
        }
        printf("\n");
    }

    return 0;
}
