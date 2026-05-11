#include <stdio.h>
#include <stdlib.h>

#define MAX 50


struct Edge {
    int src, dest, weight;
};


struct Graph {
    int V, E;
    struct Edge edges[MAX];
};


int parent[MAX];


int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}


void unionSet(int u, int v) {
    int u_root = find(u);
    int v_root = find(v);
    parent[u_root] = v_root;
}


void sortEdges(struct Graph g) {
    for (int i = 0; i < g.E - 1; i++) {
        for (int j = 0; j < g.E - i - 1; j++) {
            if (g.edges[j].weight > g.edges[j + 1].weight) {
                struct Edge temp = g.edges[j];
                g.edges[j] = g.edges[j + 1];
                g.edges[j + 1] = temp;
            }
        }
    }
}


void kruskal(struct Graph g) {
    int i, count = 0;
    int total = 0;


    for (i = 0; i < g.V; i++)
        parent[i] = i;

    sortEdges(g);

    printf("Edge \tWeight\n");

    for (i = 0; i < g.E && count < g.V - 1; i++) {
        int u = g.edges[i].src;
        int v = g.edges[i].dest;

        int set_u = find(u);
        int set_v = find(v);

        if (set_u != set_v) {
            printf("%d - %d \t%d\n", u, v, g.edges[i].weight);
            total += g.edges[i].weight;
            unionSet(set_u, set_v);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", total);
}


int main() {
    struct Graph g;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &g.V, &g.E);

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < g.E; i++) {
        scanf("%d %d %d", &g.edges[i].src,
                          &g.edges[i].dest,
                          &g.edges[i].weight);
    }

    kruskal(g);

    return 0;
}
