#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int main(void)
{
    Student s = {4001, "Sara", 18.5};

    printf("%d %s %.1f\n", s.id, s.name, s.score);
    return 0;
}
