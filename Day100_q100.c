/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdio.h>

#define MAX 100

typedef struct {
    int value;
    int index;
} Node;

Node arr[MAX], temp[MAX];
int result[MAX];

// merge function
void merge(int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    int countRight = 0;

    printf("\nMerging from %d to %d\n", left, right);

    while(i <= mid && j <= right)
    {
        if(arr[j].value < arr[i].value)
        {
            temp[k++] = arr[j++];
            countRight++;
        }
        else
        {
            result[arr[i].index] += countRight;
            temp[k++] = arr[i++];
        }
    }

    while(i <= mid)
    {
        result[arr[i].index] += countRight;
        temp[k++] = arr[i++];
    }

    while(j <= right)
    {
        temp[k++] = arr[j++];
    }

    for(int i = left; i <= right; i++)
        arr[i] = temp[i];

    printf("Partial counts: ");
    for(int i = 0; i <= right; i++)
        printf("%d ", result[i]);
    printf("\n");
}

// merge sort
void mergeSort(int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        result[i] = 0;
    }

    mergeSort(0, n - 1);

    printf("\nFinal result:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}