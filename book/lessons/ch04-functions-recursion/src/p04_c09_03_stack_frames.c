#include <stdio.h>

static char *first;

void level(int depth)
{
    int local = depth * 10;                       /* local variable of this frame */

    if (depth == 0) first = (char *)&local;
    printf("depth=%d  local=%2d  distance_from_first_frame=%ld bytes\n",
           depth, local, (long)(first - (char *)&local));

    if (depth < 3) level(depth + 1);

    printf("returning from depth=%d  (local is still %d)\n", depth, local);
}

int main(void)
{
    level(0);
    return 0;
}