#include <stdio.h>

#define MAX_STUDENTS 4
#define PASS_SCORE 10.0

int main(void)
{
    double scores[MAX_STUDENTS] = {18.5, 9.0, 14.0, 12.5};
    int passed = 0;

    for (int i = 0; i < MAX_STUDENTS; i++)
        if (scores[i] >= PASS_SCORE)
            passed++;

    printf("%d of %d passed\n", passed, MAX_STUDENTS);
    return 0;
}
