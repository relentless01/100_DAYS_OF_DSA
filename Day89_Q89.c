/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, 
allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.
Books must be allocated in contiguous order.
Input Format:
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.
*/
#include <stdio.h>

// check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages)
{
    int students = 1;
    int pages = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxPages)
            return 0;

        if(pages + arr[i] > maxPages)
        {
            students++;
            pages = arr[i];

            printf("New student allocated with %d pages\n", arr[i]);

            if(students > m)
                return 0;
        }
        else
        {
            pages += arr[i];
        }
    }

    return 1;
}

int main()
{
    int n, m;

    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int arr[n];

    printf("Enter pages in books:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int low = 0, high = 0;

    // find range
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > low)
            low = arr[i];   // max element
        high += arr[i];     // sum
    }

    int ans = high;

    printf("\nApplying Binary Search...\n");

    while(low <= high)
    {
        int mid = (low + high) / 2;

        printf("\nTrying max pages = %d\n", mid);

        if(isPossible(arr, n, m, mid))
        {
            printf("Possible → try smaller\n");
            ans = mid;
            high = mid - 1;
        }
        else
        {
            printf("Not possible → try bigger\n");
            low = mid + 1;
        }
    }

    printf("\nMinimum possible maximum pages = %d\n", ans);

    return 0;
}