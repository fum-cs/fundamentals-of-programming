#include <stdio.h>

int main(void)
{
    FILE *f = fopen("scores.txt", "w");
    if (f == NULL) {
        printf("cannot open file\n");
        return 1;
    }

    fprintf(f, "%d\n", 18);
    fprintf(f, "%d\n", 15);
    fprintf(f, "%d\n", 20);

    fclose(f);
    return 0;
}
