/*Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls
such that the minimum distance between any two cows is maximized.
This is an optimization problem where binary search on the answer is required.*/
 #include <stdio.h>
#include <stdlib.h>

// sort function
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

// check if cows can be placed
int canPlace(int stalls[], int n, int k, int dist)
{
    int count = 1; // first cow
    int last = stalls[0];

    for(int i = 1; i < n; i++)
    {
        if(stalls[i] - last >= dist)
        {
            count++;
            last = stalls[i];

            printf("Placed cow at %d\n", stalls[i]);

            if(count == k)
                return 1;
        }
    }

    return 0;
}

int main()
{
    int n, k;

    printf("Enter n and k: ");
    scanf("%d %d", &n, &k);

    int stalls[n];

    printf("Enter stall positions:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &stalls[i]);

    // sort stalls
    sort(stalls, n);

    printf("\nSorted stalls: ");
    for(int i = 0; i < n; i++)
        printf("%d ", stalls[i]);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    printf("\n\nApplying Binary Search...\n");

    while(low <= high)
    {
        int mid = (low + high) / 2;

        printf("\nTrying distance = %d\n", mid);

        if(canPlace(stalls, n, k, mid))
        {
            printf("Possible with %d → try bigger\n", mid);
            ans = mid;
            low = mid + 1;
        }
        else
        {
            printf("Not possible with %d → try smaller\n", mid);
            high = mid - 1;
        }
    }

    printf("\nMaximum minimum distance = %d\n", ans);

    return 0;
}