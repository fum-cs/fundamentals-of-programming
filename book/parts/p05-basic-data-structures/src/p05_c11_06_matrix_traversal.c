
#include <stdio.h>
#define ROWS 3
#define COLS 4

int main(void)
{
    int scores[ROWS][COLS] = {
        {18, 15, 20, 17},
        {12, 14, 16, 18},
        {20, 19, 18, 20}
    };

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }

    return 0;
}
