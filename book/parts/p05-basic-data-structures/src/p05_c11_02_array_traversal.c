
#include <stdio.h>
#define STUDENT_COUNT 5

int main(void)
{
    int scores[STUDENT_COUNT] = {18, 15, 20, 12, 17};

    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("Student %d: %d\n", i, scores[i]);
    }

    return 0;
}
