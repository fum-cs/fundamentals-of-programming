
#include <stdio.h>
#include <string.h>

int main(void)
{
    char fullName[30] = "Ali";
    strcat(fullName, " Rezaei");

    printf("%s\n", fullName);   // خروجی: Ali Rezaei

    return 0;
}
