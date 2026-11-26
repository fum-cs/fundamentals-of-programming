#include <stdio.h>

int main(void)
{
    int score;
    char grade = '?';

    if (scanf("%d", &score) != 1) {
        return 1;
    }

    if (score < 0 || score > 100) {
        printf("%d: invalid score\n", score);
        return 1;
    }

    switch (score / 10) {
        case 10:            /* only 100 */
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
    }

    printf("%d -> %c\n", score, grade);
    return 0;
}
