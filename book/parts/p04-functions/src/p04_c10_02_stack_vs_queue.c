
#include <stdio.h>
#include "adt.h"

int main(void)
{
    for (int x = 1; x <= 3; x++) {
        s_push(x);
        q_push(x);
    }

    printf("stack pops : ");
    while (!s_empty()) printf("%d ", s_pop());
    printf("\n");

    printf("queue pops : ");
    while (!q_empty()) printf("%d ", q_pop());
    printf("\n");
    return 0;
}
