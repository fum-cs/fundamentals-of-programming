#include <stdio.h>

int main(void)
{
    int total, member;

    if (scanf("%d %d", &total, &member) != 2) {
        return 1;
    }

    int independent = 0;               /* both discounts may apply */
    if (member) {
        independent += 5;
    }
    if (total >= 1000) {
        independent += 10;
    }

    int chained = 0;                   /* only the first match applies */
    if (member) {
        chained = 5;
    } else if (total >= 1000) {
        chained = 10;
    }

    printf("total=%d member=%d | independent: %d%% | chained: %d%%\n",
           total, member, independent, chained);
    return 0;
}
