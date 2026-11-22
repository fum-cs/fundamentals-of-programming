#include <stdio.h>

int main(void)
{
    int score = 5;

    if (score >= 18);
    {
        printf("1) this line runs for ANY score\n");
    }

    if (3 > 2 > 1) {
        printf("2) 3 > 2 > 1 is true\n");
    } else {
        printf("2) 3 > 2 > 1 is FALSE (surprise!)\n");
    }

    int y = 7;
    if (y == 1 || 2) {
        printf("3) y == 1 || 2 is true even for y = %d\n", y);
    }

    return 0;
}
