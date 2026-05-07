/*Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO
*/
#include <stdio.h>

int isMinHeap(int arr[], int n) {
    int i;
    
    // Check all parent nodes
    for (i = 0; i <= (n / 2) - 1; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        printf("\nChecking node %d (value = %d):\n", i, arr[i]);

        // Check left child
        if (left < n) {
            printf("  Left child index %d (value = %d)\n", left, arr[left]);
            if (arr[i] > arr[left]) {
                printf("Parent is greater than left child!\n");
                return 0;
            }
        }

        // Check right child
        if (right < n) {
            printf("  Right child index %d (value = %d)\n", right, arr[right]);
            if (arr[i] > arr[right]) {
                printf("Parent is greater than right child!\n");
                return 0;
            }
        }

        printf(" This node satisfies Min-Heap condition\n");
    }

    return 1;
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements (level-order): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n--- Checking Min Heap ---\n");

    if (isMinHeap(arr, n)) {
        printf("\nYES - It is a Min Heap\n");
    } else {
        printf("\nNO - It is NOT a Min Heap\n");
    }

    return 0;
}