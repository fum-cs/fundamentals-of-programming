
#include <stdio.h>

int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int scores[] = {12, 15, 18, 20, 17};
    int n = sizeof(scores) / sizeof(scores[0]);

    int result = linearSearch(scores, n, 18);

    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}
