/* Adjacency Matrix representation of an undirected graph in C */

#include <stdio.h>
int V=4; /* number of vertices in the graph */

/* function to initialize the matrix to zero */
void init(int arr[][V])
{
    int i, j;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            arr[i][j] = 0;
}

/* function to add edges to the graph */
void insertEdge(int arr[][V], int i, int j)
{
    arr[i][j] = 1;
    arr[j][i] = 1;
}

/* function to print the matrix elements */
void printAdjMatrix(int arr[][V])
{
    int i, j;
    printf("  ");
    for (i = 0; i < V; i++)
    {
        printf(" %d", i);
    }
    printf("\n");
    for (i = 0; i < V; i++)
    {
        printf("%d: ", i);
        for (j = 0; j < V; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int adjMatrix[V][V];

    init(adjMatrix);
    insertEdge(adjMatrix, 0, 1);
    insertEdge(adjMatrix, 0, 2);
    insertEdge(adjMatrix, 1, 2);
    insertEdge(adjMatrix, 2, 0);
    insertEdge(adjMatrix, 2, 3);

    printAdjMatrix(adjMatrix);

    return 0;
}