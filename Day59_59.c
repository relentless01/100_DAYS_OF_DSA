/*Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree
*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    printf("Creating node: %d\n", data);

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            printf("Found %d in inorder at index %d\n", value, i);
            return i;
        }
    }
    return -1;
}

// Build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    // Take root from postorder
    int current = postorder[*postIndex];
    printf("\nTaking %d as root from postorder index %d\n", current, *postIndex);

    struct Node* root = newNode(current);
    (*postIndex)--;

    // If only one node
    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, current);

    printf("Building RIGHT subtree of %d\n", current);
    root->right = buildTree(inorder, postorder, inIndex + 1, end, postIndex);

    printf("Building LEFT subtree of %d\n", current);
    root->left = buildTree(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter postorder traversal: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    printf("\n--- Building Tree ---\n");
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("\n--- Preorder Traversal ---\n");
    preorder(root);

    return 0;
}