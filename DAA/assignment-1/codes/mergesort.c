#include <stdio.h>
#include <stdlib.h>
void merge_sort(int arr[], int f, int l)
{
    int mid = f + (l - f) / 2;
    if (l - f + 1 == 1)
        return;

    merge_sort(arr, f, mid);
    merge_sort(arr, mid + 1, l);

    merge(arr, f, mid + 1, l);
}

int merge(int a[], int n1, int n2, int n3)
{
    int i1 = n1, i2 = n2, i = 0, t;
    int *ac;
    ac = (int *)malloc((n3 - n1 + 1) * sizeof(int));

    while (i1 < n2 && i2 <= n3)
    {
        if (a[i1] <= a[i2])
        {
            ac[i] = a[i1];
            i1++;
        }
        else
        {
            ac[i] = a[i2];
            i2++;
        }
        i++;
    }
    for (; i1 < n2; i1++, i++)
        ac[i] = a[i1];
    for (; i2 <= n3; i2++, i++)
        ac[i] = a[i2];
    for (i = n1, i1 = 0; i <= n3; i++, i1++)
        ac[i] = ac[i1];
    free(ac);
}
int main()
{
    int *a, i, n, data;
    printf("Enter the len: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    printf("Enter %d no. ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    merge_sort(a, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
