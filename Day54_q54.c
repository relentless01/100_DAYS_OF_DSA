/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print traversal in zigzag order

Example:
Input:
7
1 2 3 4 5 6 7

Output:
1 3 2 4 5 6 7

Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// create node
struct Node* createNode(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main()
{
    int n;
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
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct Node* root = nodes[0];

    // queue for BFS
    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1; // direction flag

    printf("\nZigzag Traversal:\n");

    while(front < rear)
    {
        int size = rear - front;
        int level[MAX];

        // store current level
        for(int i = 0; i < size; i++)
        {
            struct Node* temp = queue[front++];
            level[i] = temp->data;

            if(temp->left)
                queue[rear++] = temp->left;

            if(temp->right)
                queue[rear++] = temp->right;
        }

        // print based on direction
        if(leftToRight)
        {
            printf("Level Left → Right: ");
            for(int i = 0; i < size; i++)
                printf("%d ", level[i]);
        }
        else
        {
            printf("Level Right → Left: ");
            for(int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        printf("\n");

        leftToRight = !leftToRight; // toggle direction
    }

    return 0;
}