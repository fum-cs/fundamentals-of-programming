#include <stdio.h>

int main(void)
{
    FILE *f = fopen("scores.txt", "r");
    if (f == NULL) {
        printf("cannot open file\n");
        return 1;
    }

    int x, count = 0, sum = 0;
    while (fscanf(f, "%d", &x) == 1) {
        printf("read: %d\n", x);
        sum += x;
        count++;
    }
    fclose(f);

    if (count > 0)
        printf("count = %d, average = %.2f\n", count, (double)sum / count);
    return 0;
}
