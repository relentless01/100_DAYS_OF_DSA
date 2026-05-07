/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.22*/


#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    printf("Creating node with value: %d\n", data);

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Queue structure
struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Check if empty
int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    printf("Enqueue node: %d\n", node->data);
    q->arr[++q->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    struct Node* temp = q->arr[q->front++];
    printf("Dequeue node: %d\n", temp->data);
    return temp;
}

// Get current size
int getSize(struct Queue* q) {
    return (q->rear - q->front + 1);
}

// Build tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    printf("\n--- Building Tree ---\n");

    struct Node* root = newNode(arr[0]);

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int i = 1;

    while (i < n && !isEmpty(&q)) {
        struct Node* current = dequeue(&q);

        // Left child
        if (arr[i] != -1) {
            printf("Adding LEFT child %d to %d\n", arr[i], current->data);
            current->left = newNode(arr[i]);
            enqueue(&q, current->left);
        } else {
            printf("LEFT child of %d is NULL\n", current->data);
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            printf("Adding RIGHT child %d to %d\n", arr[i], current->data);
            current->right = newNode(arr[i]);
            enqueue(&q, current->right);
        } else if (i < n) {
            printf("RIGHT child of %d is NULL\n", current->data);
        }
        i++;
    }

    return root;
}

// Right view function
void rightView(struct Node* root) {
    if (root == NULL) return;

    printf("\n--- Computing Right View ---\n");

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int levelSize = getSize(&q);

        printf("\nProcessing new level with %d nodes\n", levelSize);

        for (int i = 0; i < levelSize; i++) {
            struct Node* current = dequeue(&q);

            printf("Visited node: %d\n", current->data);

            // 👉 RIGHT VIEW PRINT
            if (i == levelSize - 1) {
                printf("Right view node at this level: %d\n", current->data);
                printf("%d ", current->data);  // actual output
            }

            if (current->left != NULL)
                enqueue(&q, current->left);

            if (current->right != NULL)
                enqueue(&q, current->right);
        }
    }
}

// Main
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order traversal (-1 for NULL):\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("\nRight View of the Binary Tree:\n");
    rightView(root);

    return 0;
}