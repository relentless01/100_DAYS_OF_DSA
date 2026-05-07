#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 100005

typedef struct {
    int v, w;
} Edge;

Edge adj[N][100];
int adjSize[N];

int dist[N];
int visited[N];

typedef struct {
    int node, dist;
} Node;

Node heap[N];
int size = 0;

// Min Heap functions
void push(int node, int d) {
    heap[++size] = (Node){node, d};
    int i = size;

    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        Node temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i /= 2;
    }
}

Node pop() {
    Node top = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (1) {
        int left = 2*i, right = 2*i+1, smallest = i;

        if (left <= size && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right <= size && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            Node temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        } else break;
    }
    return top;
}

void dijkstra(int source, int n) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;
    push(source, 0);

    while (size > 0) {
        Node curr = pop();
        int u = curr.node;

        if (visited[u]) continue;
        visited[u] = 1;

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adjSize[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][adjSize[u]++] = (Edge){v, w};
        adj[v][adjSize[v]++] = (Edge){u, w}; // undirected
    }

    int source;
    scanf("%d", &source);

    dijkstra(source, n);

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}