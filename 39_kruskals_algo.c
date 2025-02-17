#include <stdio.h>
#include <stdlib.h>

#define INF 999

struct Edge
{
    int u, v, weight;
};

int n, parent[100]; // Maximum vertices assumed as 100

// Find function with path compression
int find(int i)
{
    if (parent[i] == -1)
        return i;
    return parent[i] = find(parent[i]);
}

// Union function using union by rank
int uni(int u, int v)
{
    int rootU = find(u); // 4
    int rootV = find(v); // 

    if (rootU != rootV)
    {
        parent[rootV] = rootU; // Merge sets
        return 1;
    }
    return 0;
}
void kruskal(struct Edge edges[], int edgeCount)
{
    int i, ne = 0, mincost = 0;

    // Initialize parent array (Disjoint Set)
    for (i = 0; i < n; i++)
        parent[i] = -1;

    printf("The edges of Minimum Cost Spanning Tree are:\n");

    for (i = 0; i < edgeCount && ne < n - 1; i++)
    {
        if (uni(edges[i].u, edges[i].v))
        {
            printf("%d edge (%d,%d) = %d\n", ++ne, edges[i].u, edges[i].v, edges[i].weight);
            for (int k = 0; k < 7; k++)
            {
                printf("%d ", parent[k]);
            }
            printf("\n");
            mincost += edges[i].weight;
        }
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int main()
{
    int i, j, edgeCount = 0;
    struct Edge edges[100]; // Max edges
    printf("Kruskal's Algorithm in C\n");
    printf("========================\n");
    n = 7;
    // the cost adjacency matrix:\n");
    int adjmat[7][7] = {
        {0, 4, 2, 0, 0, 0, 0},
        {4, 0, 7, 3, 0, 0, 20},
        {2, 7, 0, 0, 8, 0, 0},
        {0, 3, 0, 0, 6, 1, 0},
        {0, 0, 8, 6, 0, 5, 0},
        {0, 0, 0, 1, 5, 0, 0},
        {0, 20, 0, 0, 0, 0, 0},
    };
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            int weight = adjmat[i][j];
            if (weight != 0 && i < j)
            { // Avoid duplicates and diagonal elements
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].weight = weight;
                edgeCount++;
            }
        }
    }
    // Sorting edges by weight (Bubble Sort for simplicity)
    for (i = 0; i < edgeCount - 1; i++)
    {
        for (j = 0; j < edgeCount - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    kruskal(edges, edgeCount);
    return 0;
}
