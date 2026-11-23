#include <stdio.h>
#include "p08_c18_06_student.h"
#include "p08_c18_06_student.h"

int main(void)
{
    struct Student s = {4001, 18.5};

    printf("%d %.1f\n", s.id, s.score);
    return 0;
}
