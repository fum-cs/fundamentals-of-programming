#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

void bonus_copy(Student s)
{
    s.score += 1;
}

void bonus_ptr(Student *p)
{
    p->score += 1;
}

int main(void)
{
    Student a = {4001, "Sara", 18.5};

    bonus_copy(a);
    printf("after bonus_copy: %.1f\n", a.score);

    bonus_ptr(&a);
    printf("after bonus_ptr : %.1f\n", a.score);
    return 0;
}
