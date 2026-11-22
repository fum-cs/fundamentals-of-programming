#include <stdio.h>

int main(void)
{
    int shift = 3;
    char ch;

    /* read one line character by character: until newline or end of input */
    while (scanf("%c", &ch) == 1 && ch != '\n') {
        if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + shift) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + shift) % 26;
        }
        printf("%c", ch);
    }
    printf("\n");

    return 0;
}
