#include <stdio.h>
#include <stdlib.h>
#define INF 9999
int count;
void print_stk(int *stk, int top)
{
    int i;
    for (i = 0; i <= top; i++)
        printf("\t%d", stk[i] + 1);
    printf("\t%d\n", stk[0] + 1);
    count++;
}
void ham_cycle(int *mat, int n, int *v, int l, int *stk, int *c)
{
    int i;
    stk[++(*c)] = l;
    v[l] = 1;
    if (mat[l * n + 0] != INF && *c == n - 1)
        print_stk(stk, *c);
    else
        for (i = 0; i < n; i++)
            if (mat[l * n + i] != INF && v[i] == 0)
                ham_cycle(mat, n, v, i, stk, c);
    v[l] = 0;
    --(*c);
}
int main()
{
    int i, j, *graph, *v, *stk, top = -1, n, c;
    count = 0;
    printf("\nEnter number of vertices:");
    scanf("%d", &n);

    graph = (int *)malloc(n * n * sizeof(int));
    v = (int *)calloc(n, sizeof(int));
    stk = (int *)malloc(n * sizeof(int));

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
    printf("\n\tS o l u t i o n s :\n");
    ham_cycle(graph, n, v, 0, stk, &top);
    if (count == 0)
        printf("\nN o      S o l u t i o n s      F o u n d");
    else
        printf("Total no. of solution: %d", count);
    /*
	for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",(graph[i*n+j]!=INF)?graph[i*n+j]:0);
        }
        printf("\n");
    }
*/

    return 0;
}