/*Problem: BST Insert

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
    if (root == NULL) {
        printf("Inserting %d as new node\n", value);
        return createNode(value);
    }

    if (value < root->data) {
        printf("%d < %d → go left\n", value, root->data);
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        printf("%d > %d → go right\n", value, root->data);
        root->right = insert(root->right, value);
    }

    return root;
}

// inorder traversal
void inorder(struct Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    struct Node* root = NULL;

    printf("Enter %d values:\n", n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder Traversal (Sorted BST): ");
    inorder(root);

    printf("\n");

    return 0;
}