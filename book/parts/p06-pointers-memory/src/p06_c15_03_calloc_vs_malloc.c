#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *m = malloc(3 * sizeof(int));   /* garbage inside   */
    int *c = calloc(3, sizeof(int));    /* guaranteed zeros */

    printf("calloc: %d %d %d\n", c[0], c[1], c[2]);
    /* m[0..2] are indeterminate: reading them is a bug */
    m[0] = m[1] = m[2] = 7;
    printf("malloc after filling: %d %d %d\n", m[0], m[1], m[2]);

    free(m);
    free(c);
    return 0;
}
