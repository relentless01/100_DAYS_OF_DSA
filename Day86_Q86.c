/*Problem: Find the integer square root of a given non-negative integer using Binary Search. 
The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.
Input:
- First line: an integer n
Output:
- Print the integer square root of n*/
#include <stdio.h>

int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    int low = 0, high = n;
    int ans = 0;

    printf("\nApplying Binary Search...\n");

    while(low <= high)
    {
        int mid = (low + high) / 2;
        long long square = (long long)mid * mid;

        printf("Checking mid = %d → %lld\n", mid, square);

        if(square == n)
        {
            printf("Exact square root found!\n");
            printf("Answer = %d\n", mid);
            return 0;
        }
        else if(square < n)
        {
            ans = mid;  // possible answer
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("\nInteger square root = %d\n", ans);

    return 0;
}