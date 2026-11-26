#include <stdio.h>

int main(void)
{
    int year;

    if (scanf("%d", &year) != 1) {
        return 1;
    }

    int leap;
    if (year % 400 == 0) {
        leap = 1;
    } else if (year % 100 == 0) {
        leap = 0;
    } else {
        leap = (year % 4 == 0);
    }

    if (leap) {
        printf("%d: leap year\n", year);
    } else {
        printf("%d: common year\n", year);
    }

    return 0;
}
