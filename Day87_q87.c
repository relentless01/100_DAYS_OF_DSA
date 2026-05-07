/*Problem: Implement Binary Search Iterative - Implement the algorithm.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the sorted array or search result
*/
#include <stdio.h>

// function to sort (simple bubble sort)
void sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// binary search iterative
int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        printf("Checking index %d → value %d\n", mid, arr[mid]);

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    // sort first
    sort(arr, n);

    printf("\nSorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nApplying Binary Search...\n");

    int result = binarySearch(arr, n, key);

    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}