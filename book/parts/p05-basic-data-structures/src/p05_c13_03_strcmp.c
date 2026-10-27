
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "Ali";
    char str2[] = "Ali";

    if (strcmp(str1, str2) == 0) {
        printf("Equal\n");
    } else {
        printf("Not equal\n");
    }

    return 0;
}
