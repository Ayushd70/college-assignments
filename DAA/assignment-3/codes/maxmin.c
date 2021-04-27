#include <stdio.h>
#include <stdlib.h>
typedef struct tuple
{
    int max;
    int min;
} tuple;
void maxmin(int a[], int f, int l, tuple *val)
{
    int mid;
    tuple t1, t2;
    if (f == l)
        val->max = a[f], val->min = a[f];
    else if (f == l + 1)
        (a[f] > a[l]) ? (val->max = a[f], val->min = a[l]) : (val->max = a[l], val->min = a[f]);
    else
    {
        mid = (f + l) / 2;
        maxmin(a, f, mid, &t1);
        maxmin(a, mid + 1, l, &t2);
        val->max = (t1.max > t2.max) ? t1.max : t2.max, val->min = (t1.min < t2.min) ? t1.min : t2.min;
    }
}
int main()
{
    int *a, i, n;
    tuple max_min;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    printf("Enter %d number: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    maxmin(a, 0, n - 1, &max_min);

    printf("max=%d ,min=%d", max_min.max, max_min.min);
}