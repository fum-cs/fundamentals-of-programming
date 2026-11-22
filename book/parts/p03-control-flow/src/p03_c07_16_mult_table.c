#include <stdio.h>

int main(void)
{
    printf("    ");
    for (int j = 1; j <= 5; j++) {
        printf("%4d", j);
    }
    printf("\n");

    for (int i = 1; i <= 5; i++) {
        printf("%4d", i);
        for (int j = 1; j <= 5; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}
