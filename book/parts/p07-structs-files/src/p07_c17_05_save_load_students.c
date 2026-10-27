#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int save_students(const char *path, const Student *list, int n)
{
    FILE *f = fopen(path, "w");
    if (f == NULL)
        return 0;
    for (int i = 0; i < n; i++)
        fprintf(f, "%d %s %.1f\n", list[i].id, list[i].name, list[i].score);
    fclose(f);
    return 1;
}

int load_students(const char *path, Student *list, int max)
{
    FILE *f = fopen(path, "r");
    if (f == NULL)
        return 0;

    int n = 0;
    while (n < max && fscanf(f, "%d %19s %lf",
                             &list[n].id, list[n].name, &list[n].score) == 3)
        n++;
    fclose(f);
    return n;
}

int main(void)
{
    Student cls[3] = {
        {4001, "Sara", 18.5},
        {4002, "Ali", 15},
        {4003, "Mina", 20}
    };
    Student loaded[10];

    if (!save_students("students.txt", cls, 3)) {
        printf("cannot save\n");
        return 1;
    }

    int n = load_students("students.txt", loaded, 10);
    printf("loaded %d students\n", n);
    for (int i = 0; i < n; i++)
        printf("%d %s %.1f\n", loaded[i].id, loaded[i].name, loaded[i].score);
    return 0;
}
