/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value*/
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

// find LCA
struct Node* findLCA(struct Node* root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    printf("Visiting node: %d\n", root->data);

    // if current node is one of the targets
    if (root->data == n1 || root->data == n2) {
        printf("Found one node: %d\n", root->data);
        return root;
    }

    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    // if both sides return non-null → LCA
    if (left != NULL && right != NULL) {
        printf("LCA found at node: %d\n", root->data);
        return root;
    }

    // otherwise return non-null side
    return (left != NULL) ? left : right;
}

int main()
{
    int n, n1, n2;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order (-1 for NULL):\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* nodes[n];

    // create nodes
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // connect nodes
    for(int i = 0; i < n; i++)
    {
        if(nodes[i] != NULL)
        {
            int leftIndex = 2*i + 1;
            int rightIndex = 2*i + 2;

            if(leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if(rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    struct Node* root = nodes[0];

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