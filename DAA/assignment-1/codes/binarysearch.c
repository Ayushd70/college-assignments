#include <stdio.h>
#include <stdlib.h>
int binary_search(int arr[], int num, int f, int l)
{
    int mid = f + (l - f) / 2;
    if (arr[mid] == num)
        return mid;
    else if (f - l + 1 == 1)
        return -1;
    else if (arr[mid] < num)
        return binary_search(arr, num, mid + 1, l);
    else
        return binary_search(arr, num, f, mid - 1);
}

void sort(int a[], int n)
{
    int i, l, t;
    for (i = 0; i < n - 1; i++)
    {
        for (l = 0; l < n - 1 - i; l++)
            if (a[l] > a[l + 1])
            {
                t = a[l];
                a[l] = a[l + 1];
                a[l + 1] = t;
            }
    }
}

int main()
{
    int *a, i, n, data;
    printf("Enter the len: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    printf("Enter %d no. ", n);
    for (i = 0; i <= n; i++)
        scanf("%d", &a[i]);

    printf("Search: ");
    scanf("%d", &data);

    sort(a, n);

    if ((i = binary_search(a, data, 0, n - 1)) != 1)
        printf("found %d", data);
    else
        printf("%d not found", data);
}