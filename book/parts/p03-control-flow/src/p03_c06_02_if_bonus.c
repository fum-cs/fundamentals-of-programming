#include <stdio.h>

int main(void)
{
    int score;

    if (scanf("%d", &score) != 1) {
        return 1;
    }

    printf("Score: %d\n", score);
    if (score >= 18) {
        printf("Excellent! Bonus point awarded.\n");
    }
    printf("Report finished.\n");

    return 0;
}
