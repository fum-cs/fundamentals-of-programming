#include <stdio.h>

int main(void)
{
    /* BUGGY: continue skips "i++" so i stays 0 forever.
       guard < 5 is only a safety cap for this demo. */
    int i = 0, guard = 0;
    while (i < 10 && guard < 5) {
        guard++;
        if (i % 2 == 0) {
            continue;
        }
        i++;
    }
    printf("buggy version : after %d iterations i = %d (stuck)\n", guard, i);

    /* FIXED: update before continue */
    int sum = 0;
    int k = 0;
    while (k < 10) {
        k++;
        if (k % 2 == 0) {
            continue;
        }
        sum += k;
    }
    printf("fixed version : sum of odd numbers up to 10 = %d\n", sum);

    return 0;
}
