#include <stdio.h>

int main(void)
{
    int secret = 73;
    int low = 1, high = 100, count = 0;

    while (1) {
        int guess = (low + high) / 2;

        count++;
        printf("guess %d: %d\n", count, guess);

        if (guess < secret)
            low = guess + 1;
        else if (guess > secret)
            high = guess - 1;
        else
            break;
    }
    printf("found in %d guesses\n", count);
    return 0;
}
