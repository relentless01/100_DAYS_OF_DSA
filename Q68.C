#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];

int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Queue setup
    int front = 0, rear = 0;

    // Add nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    printf("Topological Order: ");

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < V; i++) {
            if (graph[node][i] == 1) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Check cycle
    if (count != V) {
        printf("\nCycle exists! Topological sort not possible.\n");
    }

    return 0;
}