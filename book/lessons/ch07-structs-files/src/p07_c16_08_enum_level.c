#include <stdio.h>

enum Level { FAIL, PASS, EXCELLENT };

enum Level classify(double score)
{
    if (score >= 18)
        return EXCELLENT;
    if (score >= 10)
        return PASS;
    return FAIL;
}

int main(void)
{
    double scores[] = {18.5, 15, 7};

    for (int i = 0; i < 3; i++) {
        switch (classify(scores[i])) {
        case EXCELLENT: printf("%.1f: excellent\n", scores[i]); break;
        case PASS:      printf("%.1f: pass\n", scores[i]);      break;
        case FAIL:      printf("%.1f: fail\n", scores[i]);      break;
        }
    }
    printf("EXCELLENT = %d\n", EXCELLENT);
    return 0;
}
