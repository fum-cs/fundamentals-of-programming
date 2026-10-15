
#include <stdio.h>
#include "adt.h"

/* C(n,k) با حلقه + Stack صریح (DFS). nodes = تعداد گره‌های دیده‌شده */
unsigned long binom_dfs(int n, int k, unsigned long *nodes)
{
    unsigned long leaves = 0;
    *nodes = 0;
    s_push(n); s_push(k);
    while (!s_empty()) {
        int kk = s_pop(), nn = s_pop();
        (*nodes)++;
        if (kk == 0 || kk == nn) {
            leaves++;                                   /* برگ: مقدار ۱ */
        } else {
            s_push(nn - 1); s_push(kk);                 /* فرزند راست (n-1, k)   */
            s_push(nn - 1); s_push(kk - 1);             /* فرزند چپ  (n-1, k-1)  */
        }
    }
    return leaves;
}

/* C(n,k) با حلقه + Queue (BFS) */
unsigned long binom_bfs(int n, int k, unsigned long *nodes)
{
    unsigned long leaves = 0;
    *nodes = 0;
    q_push(n); q_push(k);
    while (!q_empty()) {
        int nn = q_pop(), kk = q_pop();
        (*nodes)++;
        if (kk == 0 || kk == nn) {
            leaves++;
        } else {
            q_push(nn - 1); q_push(kk - 1);             /* فرزند چپ  */
            q_push(nn - 1); q_push(kk);                 /* فرزند راست */
        }
    }
    return leaves;
}

int main(void)
{
    int cases[][2] = { {5, 2}, {10, 5}, {16, 8}, {20, 10} };

    printf("  (n,k)   result   nodes   max Stack size   max Queue size\n");
    for (int i = 0; i < 4; i++) {
        int n = cases[i][0], k = cases[i][1];
        unsigned long nodes_dfs, nodes_bfs;

        unsigned long by_dfs = binom_dfs(n, k, &nodes_dfs);
        unsigned long by_bfs = binom_bfs(n, k, &nodes_bfs);

        printf("(%2d,%2d)  %7lu  %6lu  %14d  %14d   %s\n",
               n, k, by_dfs, nodes_dfs, s_max / 2, q_max / 2,
               (by_dfs == by_bfs && nodes_dfs == nodes_bfs) ? "(same)" : "(DIFFERENT!)");

        s_top = s_max = 0;  q_head = q_size = q_max = 0;      /* بازنشانی برای آزمایش بعد */
    }
    return 0;
}
