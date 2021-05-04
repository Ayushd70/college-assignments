#include <stdio.h>
typedef struct tuple
{
    int weight;
    int value;
} tuple;
int ratio(tuple a, tuple b)
{
    //printf(" %d %d*",a.weight,b.weight);
    return (a.value / (float)a.weight < b.value / (float)b.weight);
}

int weight(tuple a, tuple b)
{
    //printf(" %d %d*",a.weight,b.weight);
    return a.weight > b.weight;
}
int profit(tuple a, tuple b)
{
    //printf(" %d %d*",a.weight,b.weight);
    return a.value < b.value;
}
void sort(tuple a[], int n, int *func(tuple, tuple))
{
    int i, l;
    int t;
    for (i = 0; i < n - 1; i++)
    {
        for (l = 0; l < n - 1 - i; l++)
        {
            if (func(a[l], a[l + 1]))
            {
                //	printf("hi");
                t = a[l].weight;
                a[l].weight = a[l + 1].weight;
                a[l + 1].weight = t;

                t = a[l].value;
                a[l].value = a[l + 1].value;
                a[l + 1].value = t;
            }
        }
    }
}

float fractionalKnapsack(tuple l[], int cap, int n, float k[], int *func(tuple, tuple))
{
    int capl = cap, i;
    float v = 0;
    sort(l, n, func);

    for (i = 0; i < n && capl > 0; i++)
    {
        if (l[i].weight < capl)
        {
            k[i] = 1;
            capl -= l[i].weight;
            v += (float)l[i].value;
        }
        else
        {
            k[i] = capl / (float)l[i].weight;
            capl = 0;
            v += l[i].value * k[i];
        }
    }
    return v;
}
int main()
{
    int i, l, n, c;
    tuple *a;
    float *k, v;

    printf("Enter no. of elements ");
    scanf("%d", &n);

    printf("Enter the capacity ");
    scanf("%d", &c);

    a = (tuple *)malloc(n * sizeof(tuple));
    k = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("Enter weight & value of element %d: ", i + 1);
        scanf("%d%d", &a[i].weight, &a[i].value);
    }

    v = fractionalKnapsack(a, c, n, k, profit);

    printf("\n weight:");
    for (i = 0; i < n; i++)
        if (k[i] != 0)
            printf("%.2f\t", a[i].weight * k[i]);
    printf("\n value: ");
    for (i = 0; i < n; i++)
        if (k[i] != 0)
            printf("%.2f\t", a[i].value * k[i]);
    printf("\n     : ");
    for (i = 0; i < n; i++)
        if (k[i] != 0)
            printf("%.2f\t", k[i]);
    printf("\n total profit: %.2f", v);

    v = fractionalKnapsack(a, c, n, k, weight);

    printf("\n weight:");
    for (i = 0; i < n; i++)
        if (k[i] != 0)
            printf("%.2f\t", a[i].weight * k[i]);
    printf("\n value: ");
    for (i = 0; i < n; i++)
        if (k[i] != 0)
            printf("%.2f\t", a[i].value * k[i]);
    printf("\n     : ");
    for (i = 0; i < n; i++)
        if (k[i] != 0)
            printf("%.2f\t", k[i]);
    printf("\n total profit: %.2f", v);

    v = fractionalKnapsack(a, c, n, k, ratio);

    printf("\n weight:");
    for (i = 0; i < n; i++)
        if (k[i] != 0)
            printf("%.2f\t", a[i].weight * k[i]);
    printf("\n value: ");
    for (i = 0; i < n; i++)
        if (k[i] != 0)
            printf("%.2f\t", a[i].value * k[i]);
    printf("\n     : ");
    for (i = 0; i < n; i++)
        if (k[i] != 0)
            printf("%.2f\t", k[i]);
    printf("\n total profit: %.2f", v);

    return 0;
}