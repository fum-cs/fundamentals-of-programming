#include <stdio.h>

struct Student {
    int id;
    char name[20];
    double score;
};

int main(void)
{
    struct Student a = {4001, "Sara", 18.5};
    struct Student b = a;

    b.score = 20;
    printf("a: %s %.1f\n", a.name, a.score);
    printf("b: %s %.1f\n", b.name, b.score);
    return 0;
}
