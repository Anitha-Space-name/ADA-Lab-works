#include <stdio.h>
#include <limits.h>

#define MAX 20


struct Graph {
    int V;
    int adj[MAX][MAX];
};


int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}


void printMST(int parent[], struct Graph g) {
    int total = 0;
    printf("Edge \tWeight\n");

    for (int i = 1; i < g.V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, g.adj[i][parent[i]]);
        total += g.adj[i][parent[i]];
    }

    printf("Minimum Cost = %d\n", total);
}


void primMST(struct Graph g) {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 0; i < g.V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < g.V - 1; count++) {
        int u = minKey(key, mstSet, g.V);
        mstSet[u] = 1;

        for (int v = 0; v < g.V; v++) {
            if (g.adj[u][v] && mstSet[v] == 0 && g.adj[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g.adj[u][v];
            }
        }
    }

    printMST(parent, g);
}


int main() {
    struct Graph g;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &g.V);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < g.V; i++) {
        for (j = 0; j < g.V; j++) {
            scanf("%d", &g.adj[i][j]);
        }
    }

    primMST(g);

    return 0;
}

