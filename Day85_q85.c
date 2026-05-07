/*Problem: Implement Merge Sort - Implement the algorithm.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the sorted array or search result
*/
#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid + 1, k = low;

    printf("Merging from %d to %d\n", low, high);

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= high)
        temp[k++] = arr[j++];

    for(int i = low; i <= high; i++)
        arr[i] = temp[i];

    printf("After merge: ");
    for(int i = low; i <= high; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        printf("\nDividing from %d to %d\n", low, high);

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}