#include <stdio.h>
#include "adt.h"

/* a task is (n, from, to, via, is_move) stored as five ints */
void push_task(int n, char from, char to, char via, int is_move)
{
    s_push(n); s_push(from); s_push(to); s_push(via); s_push(is_move);
}

void hanoi_iter(int n, char from, char to, char via)
{
    push_task(n, from, to, via, 0);
    while (!s_empty()) {
        int is_move = s_pop();
        char v = (char)s_pop(), t = (char)s_pop(), f = (char)s_pop();
        int k = s_pop();

        if (is_move) {
            printf("move disk %d: %c -> %c\n", k, f, t);
        } else if (k > 0) {
            push_task(k - 1, v, t, f, 0);      /* done last : n-1 disks from via to to  */
            push_task(k, f, t, v, 1);          /* done second: a single move            */
            push_task(k - 1, f, v, t, 0);      /* done first: n-1 disks from from to via */
        }
    }
}

int main(void)
{
    hanoi_iter(3, 'A', 'C', 'B');
    return 0;
}
