#include <stdio.h>

int main(void)
{
    int s = -1;

    do {
        printf("Enter score (0-20): ");
        int got = scanf("%d", &s);

        if (got == EOF) {
            printf("\nNo more input\n");
            return 1;
        }
        if (got == 0) {                  /* text instead of a number */
            printf("Not a number\n");
            scanf("%*s");                /* throw the bad word away */
            s = -1;
        } else if (s < 0 || s > 20) {
            printf("Invalid: %d\n", s);
        }
    } while (s < 0 || s > 20);

    printf("Accepted: %d\n", s);
    return 0;
}
