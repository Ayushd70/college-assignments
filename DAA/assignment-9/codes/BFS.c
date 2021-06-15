#include <stdio.h>
#define MAX 20
//here 0 is  infinity
void Insert(int Q[], int *f, int *r, int num)
{
    if (*r == -1)
    {
        *f = 0;
        *r = 0;
        Q[*r] = num;
    }
    else
    {
        *r = *r + 1;
        Q[*r] = num;
    }
}
int Delete(int Q[], int *f, int *r)
{

    int d = Q[*f];
    if (*f == *r)
    {
        *f = -1;
        *r = -1;
    }
    else
        *f = *f + 1;

    return d;
}

void main()
{

    int n, i, j, f = -1, r = -1, num, k, pos;
    int Q[MAX];
    int a[MAX][MAX], status[MAX];
    printf("Enter No. of Nodes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n Enter for Node %c : ", i + 65);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
        status[i] = 0;

    status[0] = 1;
    num = 0;
    k = 1;
    Insert(Q, &f, &r, num);
    while (k <= n)
    {

        pos = Delete(Q, &f, &r);
        printf(" %c", pos + 65);
        status[pos] = 2;
        for (j = 0; j < n; j++)
        {
            if (a[pos][j] == 1 && status[j] == 0)
            {
                status[j] = 1;
                Insert(Q, &f, &r, j);
            }
        }

        k++;
    }
}
/*
8
0 1 0 1 1 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 1
0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1
0 0 0 0 1 0 0 0
*/
