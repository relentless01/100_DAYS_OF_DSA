/* Problem: Count Leaf Nodes

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

// function to count leaf nodes
int countLeaf(struct Node* root)
{
    if (root == NULL)
        return 0;

    // if leaf node
    if (root->left == NULL && root->right == NULL) {
        printf("Leaf node found: %d\n", root->data);
        return 1;
    }

    // count in left + right
    return countLeaf(root->left) + countLeaf(root->right);
}

int main()
{
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order values (-1 for NULL):\n");
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
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    printf("\nCounting leaf nodes...\n");

    int result = countLeaf(root);

    printf("\nTotal number of leaf nodes: %d\n", result);

    return 0;
}