#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    double score;
};

int main(void)
{
    struct Student s;

    s.id = 4001;
    strcpy(s.name, "Sara");
    s.score = 18.5;

    printf("%d %s %.1f\n", s.id, s.name, s.score);
    return 0;
}
