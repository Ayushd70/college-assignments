#include <stdio.h>
#include <stdlib.h>
#define INF 9999
int *prim(int *mat, int n, int *v)
{
    int i, j, l, j1, l1, min, sum = 0;
    int *cmat = (int *)calloc(n * n, sizeof(int));
    v[0] = 1;
    for (i = 0; i < n - 1; i++)
    {
        min = INF;
        j1 = l1 = -1;

        for (l = 0; l < n; l++)
        {
            if (v[l] == 1)
            {
                for (j = 0; j < n; j++)
                    if (mat[l * n + j] != INF && min > mat[l * n + j] && v[j] == 0)
                    {
                        min = mat[l * n + j];
                        l1 = l;
                        j1 = j;
                    }
            }
        }
        sum = sum + min;
        cmat[l1 * n + j1] = min;
        v[j1] = 1;
    }
    printf("\nWeight of MST: %d\n", sum);
    return cmat;
}
int main()
{
    int i, j, *graph, *v, n, c;
    printf("\nEnter number of vertices:");
    scanf("%d", &n);

    graph = (int *)malloc(n * n * sizeof(int));
    v = (int *)calloc(n, sizeof(int));

    printf("\nEnter adjecency matrix :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i * n + j]);
            if (graph[i * n + j] == 0)
                graph[i * n + j] = INF;
        }
    }
    printf("\nAdjecency matrix :\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%d", (graph[i * n + j] != INF) ? graph[i * n + j] : 0);
        }
        printf("\n");
    }

    graph = prim(graph, n, v);
    printf("\n\tPrims Minimum Spanning Tree path:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i * n + j] != 0)
                printf("\n%d<------>%d %d", i + 1, j + 1, (graph[i * n + j] != INF) ? graph[i * n + j] : 0);
        }
    }

    return 0;
}
/*
6
0 2 4 3 0 0
2 0 5 2 5 0
4 5 0 3 0 5
3 2 3 0 6 4
0 5 0 6 0 7
0 0 5 4 0 7

*/