#include <stdio.h>
#include <stdlib.h>
void main()
{
    int *job, *profit, *d, i, j, n;
    printf("Enter No.Of Jobs:");
    scanf("%d", &n);
    job = (int *)malloc(sizeof(int) * n);
    d = (int *)malloc(sizeof(int) * n);
    profit = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        job[i] = i + 1;
        printf("Enter Profit:");
        scanf("%d", &profit[i]);
        printf("Enter Deadline:");
        scanf("%d", &d[i]);
    }
    printf("\n");
    printf("Jobs:");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", job[i]);
    }
    printf("\n");
    printf("Profit:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", profit[i]);
    }
    printf("\n");
    printf("Deadline:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", d[i]);
    }
    int max = d[0];
    for (i = 0; i < n; i++)
    {
        if (d[i] > max)
            max = d[i];
    }
    int job1[max], k, t, l;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (profit[i] < profit[j])
            {
                t = profit[i];
                profit[i] = profit[j];
                profit[j] = t;

                k = job[i];
                job[i] = job[j];
                job[j] = k;

                l = d[i];
                d[i] = d[j];
                d[j] = l;
            }
        }
    }
    printf("\n\nSorted As Per Greedy Method:");
    printf("\nJobs:");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", job[i]);
    }
    printf("\n");
    printf("Profit:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", profit[i]);
    }
    printf("\n");
    printf("Deadline:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", d[i]);
    }

    for (i = 0; i < max - 1; i++)
    {
        for (j = i + 1; j < max; j++)
        {
            if (d[i] > d[j])
            {
                l = d[i];
                d[i] = d[j];
                d[j] = l;

                k = job[i];
                job[i] = job[j];
                job[j] = k;

                t = profit[i];
                profit[i] = profit[j];
                profit[j] = t;
            }
            else
            {
                if (d[i] == d[j])
                {
                    if (profit[i] < profit[j])
                    {
                        t = profit[i];
                        profit[i] = profit[j];
                        profit[j] = t;

                        k = job[i];
                        job[i] = job[j];
                        job[j] = k;

                        l = d[i];
                        d[i] = d[j];
                        d[j] = l;
                    }
                }
            }
        }
    }
    i = 0;
    int u = 0, v, p = 0;
    while (i < max)
    {
        p = p + profit[i];
        job1[u++] = job[i++];
    }

    printf("\n\nJobs Selected:");
    for (i = 0; i < max; i++)
    {
        printf("\t%d", job1[i]);
    }

    printf("\nProfit=%d", p);
}