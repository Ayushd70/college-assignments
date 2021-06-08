#include <stdio.h>
#define INF 999
int cnt = 0;
int size;
void print(int dist[][size]);
void floydWarshall(int graph[][size])
{
    int dist[size][size], i, j, k;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < size; k++)
    {
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                if ((dist[i][k] + dist[k][j]) < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
        print(dist);
    }
}
void print(int dist[][size])
{
    int i = 0, j = 0;
    printf("After A-%d>>> \n", ++cnt);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (dist[i][j] == INF)
                printf("%s\t", "INFINITE");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Enter the number of nodes=\n");
    scanf("%d", &size);
    int graph[size][size];
    int g = 0, h = 0;

    printf("Enter the initial matrix:-\n");
    for (g = 0; g < size; g++)
    {
        for (h = 0; h < size; h++)
        {
            scanf("%d", &graph[g][h]);
        }
    }
    printf("Initial Matrix:\n");
    for (g = 0; g < size; g++)
    {
        for (h = 0; h < size; h++)
        {
            printf("%d\t", graph[g][h]);
        }
        printf("\n");
    }
    floydWarshall(graph);
}
/*
4
0 5 999 4
999 0 6 999
2 7 0 6
999 3 1 0
*/
