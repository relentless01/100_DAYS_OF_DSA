/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value
*/

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

// find LCA
struct Node* findLCA(struct Node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    printf("Checking node: %d\n", root->data);

    // both nodes in left subtree
    if (n1 < root->data && n2 < root->data) {
        printf("Both values smaller → go left\n");
        return findLCA(root->left, n1, n2);
    }

    // both nodes in right subtree
    if (n1 > root->data && n2 > root->data) {
        printf("Both values greater → go right\n");
        return findLCA(root->right, n1, n2);
    }

    // split point → LCA found
    printf("This is the split point → LCA found\n");
    return root;
}

int main()
{
    int n, value, n1, n2;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* root = NULL;

    printf("Enter %d values:\n", n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter two nodes: ");
    scanf("%d %d", &n1, &n2);

    printf("\nFinding LCA...\n");

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("\nLCA is: %d\n", lca->data);
    else
        printf("\nLCA not found\n");

    return 0;
}