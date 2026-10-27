#include <stdio.h>
#include "adt.h"

int main(void)
{
    int level = 0, count = 0, widest = 0;

    q_push(5); q_push(0);                  /* node fib(5) at level 0 */
    while (!q_empty()) {
        int n = q_pop();
        int lv = q_pop();

        if (lv != level) {                 /* the previous level is finished */
            printf("level %d: %d nodes\n", level, count);
            if (count > widest) widest = count;
            level = lv;
            count = 0;
        }
        count++;

        if (n >= 2) {                      /* two children: fib(n-1) and fib(n-2) */
            q_push(n - 1); q_push(lv + 1);
            q_push(n - 2); q_push(lv + 1);
        }
    }
    printf("level %d: %d nodes\n", level, count);
    if (count > widest) widest = count;
    printf("maximum width = %d\n", widest);
    return 0;
}
