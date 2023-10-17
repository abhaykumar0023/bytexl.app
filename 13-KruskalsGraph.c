#include <stdio.h>
#include <stdlib.h>
#include <stdbool>

#define V 5 // Number of vertices in the graph
#define E 7 // Number of edges in the graph

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskalMST(struct Edge edges[]) {
    struct Subset subsets[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    int mstWeight = 0;
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    printf("Edges in the MST:\n");
    for (int i = 0, count = 0; count < V - 1; i++) {
        int srcRoot = find(subsets, edges[i].src);
        int destRoot = find(subsets, edges[i].dest);
        if (srcRoot != destRoot) {
            printf("(%d, %d) weight: %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(subsets, srcRoot, destRoot);
            count++;
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7},
        {3, 4, 9}
    };
    kruskalMST(edges);
    return 0;
}
