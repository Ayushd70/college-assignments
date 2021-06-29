#include <stdio.h>
#include <stdlib.h>
#define INF 9999
int *color, *dfs, di, count;
void color_graph(int *mat, int m, int col, int it)
{
    int *w, top = -1;
    int i, c, l, j, k, f;

    if (it >= m)
    {
        printf("*");
        for (i = 0; i < m; i++)
            printf("\t %d ", 1 + color[i]);
        printf("\n");
        count++;
        return;
    }
    j = dfs[it];
    for (c = 0; c < col; c++)
    {
        f = 0;
        for (i = 0; i < m; i++)
        {
            if (i != j && mat[j * m + i] != INF && color[i] == c)
                f = 1;
        }
        if (f == 0)
        {
            color[j] = c;

            color_graph(mat, m, col, it + 1);
            color[j] = -1;
        }
    }
}
int DepthFirstSearch(int *graph, int n, int i)
{
    int j;
    // printf("\tV%d", i+1);
    dfs[di++] = i;

    color[i] = -1;
    for (j = 0; j < n; j++)
    {
        if (!color[j] && graph[i * n + j] == 1)
        {
            DepthFirstSearch(graph, n, j);
        }
    }
    return 0;
}

int main()
{
    int i, j, *graph, n, c;
    printf("\nEnter number of vertices:");
    scanf("%d", &n);

    printf("\nEnter number of colors:");
    scanf("%d", &c);

    graph = (int *)malloc(n * n * sizeof(int));
    color = (int *)calloc(n, sizeof(int));
    dfs = (int *)calloc(n, sizeof(int));
    di = 0;
    count = 0;

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
    DepthFirstSearch(graph, n, 0);
    color_graph(graph, n, c, 0);

    printf("Total no. of solution: %d", count);

    return 0;
}
/*

4
3
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
*/