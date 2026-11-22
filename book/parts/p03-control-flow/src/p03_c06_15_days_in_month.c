#include <stdio.h>

int main(void)
{
    int month, year, days = 0;

    if (scanf("%d %d", &month, &year) != 2) {
        return 1;
    }

    switch (month) {
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            if (year % 400 == 0) {
                days = 29;
            } else if (year % 100 == 0) {
                days = 28;
            } else {
                days = (year % 4 == 0) ? 29 : 28;
            }
            break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        default:
            printf("Invalid month: %d\n", month);
            return 1;
    }

    printf("Month %d of year %d has %d days\n", month, year, days);
    return 0;
}
