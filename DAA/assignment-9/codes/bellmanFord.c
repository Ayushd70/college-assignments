#include <stdio.h>
#include <stdlib.h>
void table_printer(int *matrix, int m, int n)
{
    int i, j;
    printf("\t");
    for (i = 0; i < n; i++)
        printf("%d\t", i + 1);
    printf("\n\t--------------------------------------------------------\n");
    for (i = 0; i < m; i++)
    {
        printf("%d|\t", i + 1);
        for (j = 0; j < n; j++)
        {
            if (j == 0)
                printf("0\t");
            else
            {
                if (*(matrix + (n - 1) * i + j - 1) == 9999)
                    printf("Inf\t");
                else
                    printf("%d\t", *(matrix + (n - 1) * i + j - 1));
            }
        }
        printf("\n");
    }
}

int main()
{
    int n, i, j, k, val, min;
    printf("Number of edges:");
    scanf("%d", &n);

    printf("\n\n----------Data Entry----------------------------------------\n\n");

    int *adjacency = (int *)malloc(n * (n - 1) * sizeof(int));

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (i == j)
                *(adjacency + (n - 1) * i + j - 1) = 0;
            else
            {
                printf("Enter weight for %d -> %d ( inf = 9999 ): ", i + 1, j + 1);
                scanf("%d", &val);
                *(adjacency + (n - 1) * i + j - 1) = val;
            }
        }
    }
    printf("\n\n----------Adjacency Matrix---------------------------------\n\n");
    table_printer(adjacency, n, n);

    int *result = (int *)malloc((n - 1) * (n - 1) * sizeof(int));
    for (j = 1; j < n; j++)
    {
        *(result + j - 1) = *(adjacency + j - 1);
    }
    for (k = 2; k <= n - 1; k++)
    {
        for (j = 2; j <= n; j++)
        {
            min = 9999;
            for (i = 2; i <= n; i++)
            {
                val = *(result + (n - 1) * (k - 2) + (i - 2)) + *(adjacency + (n - 1) * (i - 1) + (j - 2));
                if (val < min)
                    min = val;
            }
            *(result + (n - 1) * (k - 1) + (j - 2)) = min;
        }
    }
    printf("\n\n----------Results-------------------------------------------------\n\n");
    table_printer(result, n - 1, n);
}
/*
5
6
5
5
9999
9999
9999
-1
-2
9999
1
9999
-2
2
9999
9999
9999
9999
*/
