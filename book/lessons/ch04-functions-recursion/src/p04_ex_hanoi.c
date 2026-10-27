#include <stdio.h>

static unsigned long moves, calls, depth, max_depth;

void hanoi(int n, char from, char to, char via, int verbose)
{
    calls++;
    depth++;
    if (depth > max_depth) max_depth = depth;

    if (n > 0) {
        hanoi(n - 1, from, via, to, verbose);        /* move n-1 disks out of the way */
        moves++;
        if (verbose) printf("move disk %d: %c -> %c\n", n, from, to);
        hanoi(n - 1, via, to, from, verbose);        /* put them on top of disk n     */
    }
    depth--;
}

int main(void)
{
    hanoi(3, 'A', 'C', 'B', 1);

    printf("\n  n     moves     calls   max depth\n");
    int tests[] = {1, 2, 3, 10, 20};
    for (int i = 0; i < 5; i++) {
        moves = calls = depth = max_depth = 0;
        hanoi(tests[i], 'A', 'C', 'B', 0);
        printf("%3d  %8lu  %8lu  %10lu\n", tests[i], moves, calls, max_depth);
    }
    return 0;
}
