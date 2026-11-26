#include <stdio.h>
#include <stdlib.h>

#define IS_PASSED(score, limit) ((score) >= (limit))

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("usage: %s <limit> <score1> [score2 ...]\n", argv[0]);
        return 1;
    }

    int limit = atoi(argv[1]);
    int passed = 0;

    for (int i = 2; i < argc; i++) {
        int score = atoi(argv[i]);
#ifdef DEBUG
        printf("[DEBUG] score=%d -> %s\n", score,
               IS_PASSED(score, limit) ? "pass" : "fail");
#endif
        if (IS_PASSED(score, limit))
            passed++;
    }

    printf("limit: %d | scores: %d | passed: %d\n", limit, argc - 2, passed);
    return 0;
}
