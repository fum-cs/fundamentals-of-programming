#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("usage: %s <number>\n", argv[0]);
        return 1;
    }

    char *end;
    long value = strtol(argv[1], &end, 10);

    if (end == argv[1] || *end != '\0') {
        printf("\"%s\" is not a valid integer\n", argv[1]);
        return 1;
    }

    printf("value = %ld\n", value);
    return 0;
}
