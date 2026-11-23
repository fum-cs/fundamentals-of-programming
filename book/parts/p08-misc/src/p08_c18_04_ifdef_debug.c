#include <stdio.h>

int main(void)
{
    int scores[] = {18, 14, 20};
    int sum = 0;

#ifndef DEBUG
    printf("Running in RELEASE mode.\n");
#endif

    for (int i = 0; i < 3; i++) {
        sum += scores[i];
#ifdef DEBUG
        printf("[DEBUG] i=%d, scores[i]=%d, sum=%d\n", i, scores[i], sum);
#endif
    }

    printf("Average: %.2f\n", sum / 3.0);
    return 0;
}
