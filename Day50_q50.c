/*Problem: BST Search

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// insert into BST
struct Node* insert(struct Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// search in BST
int search(struct Node* root, int key)
{
    if (root == NULL) {
        printf("Reached NULL → Not Found\n");
        return 0;
    }

    printf("Checking node: %d\n", root->data);

    if (key == root->data) {
        printf("Key %d found!\n", key);
        return 1;
    }

    if (key < root->data) {
        printf("%d < %d → go left\n", key, root->data);
        return search(root->left, key);
    } else {
        printf("%d > %d → go right\n", key, root->data);
        return search(root->right, key);
    }
}

int main()
{
    int n, value, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    struct Node* root = NULL;

    printf("Enter %d values:\n", n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    printf("\nSearching...\n");

    int found = search(root, key);

    if(found)
        printf("Result: Found\n");
    else
        printf("Result: Not Found\n");

    return 0;
}