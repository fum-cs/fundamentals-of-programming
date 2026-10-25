
#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main(void)
{
    int scores[] = {5, 8, 12, 15, 20, 25, 30};
    int n = sizeof(scores) / sizeof(scores[0]);

    int result = binarySearch(scores, n, 20);

    if (result != -1) {
        printf("Found at index %d\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}
