
#include <stdio.h>
#include <string.h>

int main(void)
{
    char source[] = "Ali";
    char destination[20];

    strcpy(destination, source);
    printf("%s\n", destination);

    return 0;
}
