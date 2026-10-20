#include <stdio.h>

int write_text(const char *mode, const char *text)
{
    FILE *f = fopen("names.txt", mode);
    if (f == NULL)
        return 0;
    fprintf(f, "%s", text);
    fclose(f);
    return 1;
}

void show(const char *title)
{
    char name[20];
    FILE *f = fopen("names.txt", "r");

    printf("%s:", title);
    while (f != NULL && fscanf(f, "%19s", name) == 1)
        printf(" %s", name);
    printf("\n");
    if (f != NULL)
        fclose(f);
}

int main(void)
{
    write_text("w", "Ali\nSara\nMina\n");
    show("created ");

    write_text("a", "Reza\n");
    show("after a ");

    write_text("w", "Neda\n");
    show("after w ");
    return 0;
}
