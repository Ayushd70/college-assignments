#include <stdio.h>
#include <conio.h>

void swap(int *x, int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}
void sort(int *a1, int *a2, int *ar, int s, int f)
{
    int pivot;
    int i, l;

    if (s < f)
    {
        pivot = f;
        i = s;
        l = f;
        while (i < l)
        {
            while (ar[i] < ar[pivot])
                i++;
            while (ar[l] >= ar[pivot] && l > s)
                l--;

            if (i < l)
            {
                swap(&ar[i], &ar[l]);
                swap(&a1[i], &a1[l]);
                swap(&a2[i], &a2[l]);
            }
        }

        swap(&ar[i], &ar[pivot]);
        swap(&a1[i], &a1[pivot]);
        swap(&a2[i], &a2[pivot]);

        sort(a1, a2, ar, s, i - 1);
        sort(a1, a2, ar, i + 1, f);
    }
}
void main()
{

    int s[21], f[21], i, k, j, n, a[21];
    //clrscr();
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    printf("Enter start and finish time: ");
    for (i = 0; i < n; i++)
    { //taking input
        a[i] = i + 1;
        printf("a[%d] ", a[i]);
        scanf("%d", &s[i]);
        scanf("%d", &f[i]);
    }

    sort(a, s, f, 0, n - 1);

    /*for (i = 0; i < n; i++) {							//sorting the elements
    for (j = 0; j < n - i - 1; j++) {
      if (f[j] > f[j + 1]) {
        swap( & f[j], & f[j + 1]);
        swap( & s[j], & s[j + 1]);
      }
    }
  }*/

    printf("Activities are ");
    printf("a[%d] ", a[0]);
    k = 0; //initialize with 1st element
    for (i = 0; i < n; i++)
    {
        if (s[i] >= f[k])
        {
            printf("a[%d] ", a[i]);
            k = i;
        }
    }
    getch();
}
