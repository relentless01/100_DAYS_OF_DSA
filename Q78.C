#include <stdio.h>
#include <limits.h>

#define N 100

int n, m;
int graph[N][N];

int minKey(int key[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int prim() {
    int key[N], visited[N];
    
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0; // start from node 1
    int total = 0;

    for (int i = 1; i <= n; i++) {
        int u = minKey(key, visited);
        visited[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return total;
}

int main() {
    scanf("%d %d", &n, &m);

    // initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = graph[v][u] = w;
    }

    printf("%d\n", prim());
    return 0;
}