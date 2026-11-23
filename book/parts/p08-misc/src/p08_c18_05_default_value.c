#include <stdio.h>

#ifndef PASS_SCORE
#define PASS_SCORE 10
#endif

int main(void)
{
    int score = 11;

    printf("limit = %d, score = %d: %s\n", PASS_SCORE, score,
           score >= PASS_SCORE ? "pass" : "fail");
    return 0;
}
