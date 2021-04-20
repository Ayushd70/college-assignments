#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int f, int l)
{
    int t, i, j, pivot = f;
    if (f < l)
    {
        i = f;
        j = l;
        while (i < j)
        {
            while (arr[pivot] >= arr[i] && i < l)
                i++;
            while (arr[pivot] < arr[j])
                j--;
            if (i < j)
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }

        t = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = t;

        quickSort(arr, f, j - 1);
        quickSort(arr, j + 1, l);
    }
}

int main()
{
    int n, *a, i;
    printf("Enter the no of element:");
    scanf("%d", &n);
    printf("\nEnter %d numbers: ", n);
    a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    for (i = 0; i < n; i++)
        printf(" %d", a[i]);

    return 0;
}