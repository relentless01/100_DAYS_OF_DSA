#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int parent, bool* visited, int** adj, int* adj_sizes) {
    visited[node] = true;
    for (int i = 0; i < adj_sizes[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, visited, adj, adj_sizes)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

char* has_cycle(int n, int** adj, int* adj_sizes) {
    bool* visited = (bool*)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj, adj_sizes)) {
                free(visited);
                return "YES";
            }
        }
    }
    free(visited);
    return "NO";
}