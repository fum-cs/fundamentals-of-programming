#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main(void)
{
    int scores[] = {18, 15, 20, 12, 17};
    int n = sizeof(scores) / sizeof(scores[0]);

    insertionSort(scores, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    return 0;
}
