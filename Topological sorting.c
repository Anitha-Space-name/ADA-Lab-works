#include <stdio.h>

#define MAX 10

int adj[MAX][MAX], visited[MAX];
int n;

void topoDFS(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            topoDFS(i);
    }
    printf("%d ", v);
}

int main() {
    int e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (from to):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }


    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Topological Sort Order: ");
    for (int i = 0; i < n; i++)
        if (!visited[i])
            topoDFS(i);
    printf("\n");

    return 0;
}
