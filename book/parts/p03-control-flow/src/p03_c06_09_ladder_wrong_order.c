#include <stdio.h>

int main(void)
{
    int score;

    if (scanf("%d", &score) != 1) {
        return 1;
    }

    /* BUG: conditions are in the wrong order */
    if (score >= 10) {
        printf("%d: Pass\n", score);
    } else if (score >= 14) {
        printf("%d: Good\n", score);
    } else if (score >= 17) {
        printf("%d: Excellent\n", score);
    } else {
        printf("%d: Fail\n", score);
    }

    return 0;
}
