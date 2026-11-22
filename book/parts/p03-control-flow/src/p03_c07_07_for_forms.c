#include <stdio.h>

int main(void)
{
    printf("Up:     ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }

    printf("\nDown:   ");
    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }

    printf("\nStep 2: ");
    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }

    printf("\nTwo variables: ");
    for (int lo = 0, hi = 6; lo < hi; lo++, hi--) {
        printf("(%d,%d) ", lo, hi);
    }
    printf("\n");

    return 0;
}
