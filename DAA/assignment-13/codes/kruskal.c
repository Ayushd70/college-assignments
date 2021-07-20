#include <stdio.h>
#define MAX 20
#define infinite 99999
int parent[MAX];
void main()
{
    int n, ar[MAX][MAX];
    int i, j, ne = 1, tot = 0, min, a, b, u, v;
    printf("Enter No. of vertex : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("\n Value of matrix : ");
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &ar[i][j]);
            if (ar[i][j] == 0)
                ar[i][j] = infinite;
        }
    }
    while (ne < n)
    {
        min = infinite;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (ar[i][j] < min)
                {
                    min = ar[i][j];
                    a = i;
                    u = i;
                    b = j;
                    v = j;
                }
            }
        }
        u = findparent(u);
        v = findparent(v);
        if (UNION(u, v) == 1)
        {
            printf("\n %c to %c = %d", a + 64, b + 64, min);
            tot = tot + min;
            ne++;
        }
        ar[a][b] = infinite;
        ar[b][a] = infinite;
    }
    printf("\n Total cost %d", tot);
}
int findparent(int x)
{
    while (parent[x]) // not equal zero
        x = parent[x];
    return x;
}
int UNION(int x, int y)
{
    if (x != y) // not equal means not form a cycle
    {
        parent[y] = x;
        return 1;
    }
    return 0; // when form a cycle so discard it
