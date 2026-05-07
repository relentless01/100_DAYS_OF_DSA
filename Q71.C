#include <stdio.h>

#define EMPTY -1

int hashTable[100];

// Insert function
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (hashTable[index] == EMPTY) {
            hashTable[index] = key;
            return;
        }
        i++;
    }

    printf("Hash Table is Full\n");
}

// Search function
void search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (hashTable[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (hashTable[index] == EMPTY) {
            break;  // Stop early
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, n;
    scanf("%d", &m);  // size of hash table
    scanf("%d", &n);  // number of operations

    // Initialize table
    for (int i = 0; i < m; i++) {
        hashTable[i] = EMPTY;
    }

    char operation[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", operation, &key);

        if (operation[0] == 'I') {
            insert(key, m);
        } else if (operation[0] == 'S') {
            search(key, m);
        }
    }

    return 0;
}