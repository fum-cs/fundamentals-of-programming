
#include <stdio.h>
#define STUDENT_COUNT 5

int main(void)
{
    int scores[STUDENT_COUNT] = {18, 15, 20, 12, 17};
    int sum = 0;

    for (int i = 0; i < STUDENT_COUNT; i++) {
        sum += scores[i];
    }

    double average = sum / (double)STUDENT_COUNT;
    printf("Sum: %d, Average: %.2f\n", sum, average);

    return 0;
}
