#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char votes[100][50];

    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    int maxVotes = 0;
    char winner[50];

    for (int i = 0; i < n; i++) {
        int count = 0;

        // Count occurrences
        for (int j = 0; j < n; j++) {
            if (strcmp(votes[i], votes[j]) == 0) {
                count++;
            }
        }

        // Update winner
        if (count > maxVotes) {
            maxVotes = count;
            strcpy(winner, votes[i]);
        } 
        else if (count == maxVotes) {
            if (strcmp(votes[i], winner) < 0) {
                strcpy(winner, votes[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}