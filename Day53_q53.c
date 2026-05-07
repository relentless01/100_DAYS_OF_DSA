/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// queue structure
struct Pair {
    struct Node* node;
    int hd;
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
    struct Pair queue[MAX];
    int front = 0, rear = 0;

    // array to store vertical lines
    int vertical[2*MAX][MAX];
    int count[2*MAX] = {0};

    int offset = MAX; // to handle negative index

    // push root
    queue[rear++] = (struct Pair){root, 0};

    printf("\nProcessing nodes...\n");

    while(front < rear)
    {
        struct Pair temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        printf("Node %d at HD %d\n", curr->data, hd);

        vertical[hd + offset][count[hd + offset]++] = curr->data;

        if(curr->left != NULL)
            queue[rear++] = (struct Pair){curr->left, hd - 1};

        if(curr->right != NULL)
            queue[rear++] = (struct Pair){curr->right, hd + 1};
    }

    printf("\nVertical Order Traversal:\n");

    // print from left to right
    for(int i = 0; i < 2*MAX; i++)
    {
        if(count[i] > 0)
        {
            for(int j = 0; j < count[i]; j++)
                printf("%d ", vertical[i][j]);

            printf("\n");
        }
    }

    return 0;
}