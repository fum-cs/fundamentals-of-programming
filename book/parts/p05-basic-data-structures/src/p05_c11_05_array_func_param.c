
#include <stdio.h>
#define STUDENT_COUNT 5

int sumArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    int scores[STUDENT_COUNT] = {18, 15, 20, 12, 17};
    printf("Sum: %d\n", sumArray(scores, STUDENT_COUNT));
    return 0;
}
