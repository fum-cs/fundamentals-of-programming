#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int main(void)
{
    Student cls[3] = {
        {4001, "Sara", 18.5},
        {4002, "Ali", 15},
        {4003, "Mina", 20}
    };
    Student s;

    FILE *f = fopen("students.bin", "wb");
    if (f == NULL)
        return 1;
    fwrite(cls, sizeof(Student), 3, f);
    fclose(f);

    f = fopen("students.bin", "rb");
    if (f == NULL)
        return 1;
    while (fread(&s, sizeof(Student), 1, f) == 1)
        printf("%d %s %.1f\n", s.id, s.name, s.score);
    fclose(f);

    printf("sizeof(Student) = %zu\n", sizeof(Student));
    return 0;
}
