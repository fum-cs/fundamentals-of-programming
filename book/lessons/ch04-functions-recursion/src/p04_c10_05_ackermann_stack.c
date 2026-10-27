#include <stdio.h>
#include "adt.h"

/* recursive version, for comparison */
unsigned long ack_rec(unsigned long m, unsigned long n)
{
    return m == 0 ? n + 1 : n == 0 ? ack_rec(m - 1, 1) : ack_rec(m - 1, ack_rec(m, n - 1));
}

/* loop + explicit Stack version; steps = number of loop iterations */
unsigned long ack_iter(unsigned long m, unsigned long n, unsigned long *steps)
{
    s_top = s_max = 0;
    *steps = 0;
    s_push((int)m);

    while (!s_empty()) {
        m = (unsigned long)s_pop();
        (*steps)++;
        if (m == 0) {
            n = n + 1;
        } else if (n == 0) {
            s_push((int)m - 1);
            n = 1;
        } else {
            s_push((int)m - 1);
            s_push((int)m);
            n = n - 1;
        }
    }
    return n;
}

int main(void)
{
    unsigned long steps, value;

    int same = 1, count = 0;
    for (unsigned long m = 0; m <= 3; m++) {
        for (unsigned long n = 0; n <= 5; n++) {
            count++;
            if (ack_iter(m, n, &steps) != ack_rec(m, n)) same = 0;
        }
    }
    printf("iterative == recursive on %d inputs?  %s\n\n", count, same ? "yes" : "NO");

    value = ack_iter(3, 3, &steps);
    printf("A(3,3) = %-4lu steps = %-7lu max Stack size = %d\n", value, steps, s_max);
    value = ack_iter(3, 6, &steps);
    printf("A(3,6) = %-4lu steps = %-7lu max Stack size = %d\n", value, steps, s_max);
    value = ack_iter(4, 0, &steps);
    printf("A(4,0) = %-4lu steps = %-7lu max Stack size = %d\n", value, steps, s_max);
    return 0;
}