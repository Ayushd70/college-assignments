#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void maxHeapify(int a[], int n, int idx)
{
    int max = idx;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    if (left < n && a[left] > a[max])
        max = left;
    if (right < n && a[right] > a[max])
        max = right;
    if (max != idx)
    {
        swap(&a[max], &a[idx]);
        maxHeapify(a, n, max);
    }
}
void heap_sort(int a[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);
    for (i = n - 1; i >= 0; i--)
    {
        swap(&a[i], &a[0]);
        maxHeapify(a, i, 0);
    }
}
int main()
{
    int *a, i, n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    printf("Enter %d number: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    heap_sort(a, n);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}