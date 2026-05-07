/*Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.*/


#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left    = 2 * i + 1;
    int right   = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp        = arr[i];
        arr[i]          = arr[largest];
        arr[largest]    = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    // Phase 1: Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Phase 2: Extract max one by one
    for (int i = n - 1; i > 0; i--) {
        int temp    = arr[0];
        arr[0]      = arr[i];
        arr[i]      = temp;
        heapify(arr, i, 0);
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d%s", arr[i], i < n - 1 ? ", " : "\n");
}

int main() {
    int tests[][10] = {
        {3, 6, 8, 10, 1, 2, 1},
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5},
        {42},
        {7, 7, 7, 7},
        {-5, -1, -3, -2, -4},
        {3, -1, 4, -1, 5, 9, -2},
    };
    int sizes[]  = {7, 5, 5, 1, 4, 5, 7};
    char *labels[] = {
        "Mixed values",
        "Reverse sorted",
        "Already sorted",
        "Single element",
        "All duplicates",
        "All negatives",
        "Mixed pos/neg",
    };
    int num_tests = 7;

    for (int t = 0; t < num_tests; t++) {
        printf("%-20s before: ", labels[t]);
        print_array(tests[t], sizes[t]);

        heap_sort(tests[t], sizes[t]);

        printf("%-20s after:  ", "");
        print_array(tests[t], sizes[t]);
        printf("\n");
    }

    return 0;
}
