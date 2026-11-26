#include <stdio.h>

int main(void)
{
    int n = -7;

    printf("n %% 2 = %d\n", n % 2);

    if (n % 2 == 1) {
        printf("version 1 (n %% 2 == 1): odd\n");
    } else {
        printf("version 1 (n %% 2 == 1): even   <-- wrong!\n");
    }

    if (n % 2 != 0) {
        printf("version 2 (n %% 2 != 0): odd\n");
    } else {
        printf("version 2 (n %% 2 != 0): even\n");
    }

    return 0;
}
