#include <stdio.h>
#include <stdlib.h>

int global_counter = 42;            /* Static / Global region */

void some_function(void) { }        /* Code region */

int main(void)
{
    static int static_var = 7;      /* Static region */
    int local_var = 1;              /* Stack */
    int *heap_var = malloc(sizeof(int));   /* Heap */

    printf("code  (function) : %p\n", (void *)some_function);
    printf("data  (global)   : %p\n", (void *)&global_counter);
    printf("data  (static)   : %p\n", (void *)&static_var);
    printf("heap  (malloc)   : %p\n", (void *)heap_var);
    printf("stack (local)    : %p\n", (void *)&local_var);

    free(heap_var);
    return 0;
}