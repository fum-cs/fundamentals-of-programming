
#include <stdio.h>
#include <string.h>

int main(void)
{
    char names[5][20] = {"Ali", "Sara", "Reza", "Mina", "Hasan"};

    for (int i = 0; i < 5; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
