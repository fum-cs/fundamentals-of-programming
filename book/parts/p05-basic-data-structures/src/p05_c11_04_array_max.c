
#include <stdio.h>
#define STUDENT_COUNT 5

int main(void)
{
    int scores[STUDENT_COUNT] = {18, 15, 20, 12, 17};
    int max = scores[0];

    for (int i = 1; i < STUDENT_COUNT; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }

    printf("Max grade: %d\n", max);
    return 0;
}
