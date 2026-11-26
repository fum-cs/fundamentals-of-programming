#include <stdio.h>

int main(void)
{
    int level = 2;

    printf("--- without break ---\n");
    switch (level) {
        case 3:
            printf("A ");
        case 2:
            printf("B ");
        case 1:
            printf("C ");
        default:
            printf("D ");
    }
    printf("\n");

    printf("--- with break ---\n");
    switch (level) {
        case 3:
            printf("A ");
            break;
        case 2:
            printf("B ");
            break;
        case 1:
            printf("C ");
            break;
        default:
            printf("D ");
    }
    printf("\n");

    return 0;
}
