#include <stdio.h>

typedef struct {
    int id;
    char name[20];
    double score;
} Student;

int main(void)
{
    Student cls[4] = {
        {4001, "Sara", 18.5},
        {4002, "Ali", 15},
        {4003, "Mina", 20},
        {4004, "Reza", 12.5}
    };
    double sum = 0;
    Student *best = &cls[0];

    for (int i = 0; i < 4; i++) {
        sum += cls[i].score;
        if (cls[i].score > best->score)
            best = &cls[i];
    }

    printf("average = %.2f\n", sum / 4);
    printf("best    = %s (%.1f)\n", best->name, best->score);
    return 0;
}
