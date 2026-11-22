#include <stdio.h>

int main(void)
{
    int score;

    if (scanf("%d", &score) != 1) {
        return 1;
    }

    if (score < 0 || score > 20) {
        printf("%d: invalid score (must be between 0 and 20)\n", score);
        return 1;
    }

    printf("%d: valid score\n", score);
    return 0;
}
