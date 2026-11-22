#include <stdio.h>

int main(void)
{
    /* Version 1: goto out of both loops */
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i * j == 24 && i + j == 10) {
                printf("goto version: i = %d, j = %d\n", i, j);
                goto found;
            }
        }
    }
    printf("goto version: not found\n");
found:

    /* Version 2: a flag in both loop conditions */
    int fi = 0, fj = 0, done = 0;
    for (int i = 1; i <= 9 && !done; i++) {
        for (int j = 1; j <= 9 && !done; j++) {
            if (i * j == 24 && i + j == 10) {
                fi = i;
                fj = j;
                done = 1;
            }
        }
    }
    if (done) {
        printf("flag version: i = %d, j = %d\n", fi, fj);
    } else {
        printf("flag version: not found\n");
    }

    return 0;
}
