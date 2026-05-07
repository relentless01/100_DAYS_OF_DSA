#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node;
    int dist;
} Node;

Node heap[MAX];
int size = 0;

// Swap
void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heapify
void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Push into heap
void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

// Pop min
Node pop() {
    Node root = heap[0];
    heap[0] = heap[--size];
    heapifyDown(0);
    return root;
}

// Dijkstra
void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        Node curr = pop();
        int u = curr.node;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] > 0) { // edge exists
                int newDist = dist[u] + graph[u][v];

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    push(v, newDist);
                }
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src);

    return 0;
}