/*Problem Statement:
Perform inorder, preorder, and postorder traversals of a given binary tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)

Output Format:
- Print inorder, preorder, and postorder traversals*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

// create new node
struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// inorder traversal
void inorder(struct Node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// preorder traversal
void preorder(struct Node* root)
{
    if(root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// postorder traversal
void postorder(struct Node* root)
{
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order traversal:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* nodes[n];

    // create nodes
    for(int i = 0; i < n; i++)
        nodes[i] = createNode(arr[i]);

    // connect nodes
    for(int i = 0; i < n; i++)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n)
            nodes[i]->left = nodes[left];

        if(right < n)
            nodes[i]->right = nodes[right];
    }

    struct Node* root = nodes[0];

    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal:\n");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal:\n");
    postorder(root);
    printf("\n");

    return 0;
}