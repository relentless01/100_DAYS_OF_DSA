#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, maxLen = 0;

    // Simple hashmap using array (offset technique)
    int hash[20001];  // supports negative sums
    for (int i = 0; i < 20001; i++) {
        hash[i] = -1;
    }

    int offset = 10000;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        if (hash[sum + offset] != -1) {
            int len = i - hash[sum + offset];
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            hash[sum + offset] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}