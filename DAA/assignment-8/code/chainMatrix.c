#include <stdio.h>
#include <stdlib.h>
#define inf 99999
void print_mat(int *mat, int dim)
{
    int i, l;
    printf("\nMatrix:\n");
    for (i = 0; i < dim; i++)
    {
        for (l = 0; l < dim; l++)
            (i - l <= 0) ? printf("%15d", mat[i * dim + l]) : printf("%15c", '*');
        printf("\n");
    }
}
void chain_mul(int *p, int *mat, int *s, int n)
{
    int i, l, j, k, q, dim = n - 1;

    for (i = 0; i < dim; i++)
        mat[i * dim + i] = s[i * dim + i] = 0;

    //print_mat(mat,dim);

    for (l = 1; l < dim; l++)
    {
        for (i = 0; i < dim - l; i++)
        {
            j = i + l;
            mat[i * dim + j] = inf;
            for (k = i; k < j; k++)
            {
                q = mat[i * dim + k] + mat[(k + 1) * dim + j] + p[i] * p[k + 1] * p[j + 1];
                if (q < mat[i * dim + j])
                {
                    mat[i * dim + j] = q;
                    s[i * dim + j] = k + 1;
                }
            }
        }
        //print_mat(mat,dim);
    }
}
void print_optimal(int *s, int dim, int i, int j)
{
    if (i == j)
        printf(" A%d ", i + 1);
    else
    {
        printf("( ");
        print_optimal(s, dim, i, s[i * dim + j] - 1);
        print_optimal(s, dim, s[i * dim + j], j);
        printf(" )");
    }
}
int main()
{
    int n, *mat, *ar, *s;
    int i;

    printf("\n Enter the total no. of matries: ");
    scanf("%d", &n);

    mat = (int *)malloc(n * n * sizeof(int));
    ar = (int *)malloc((n + 1) * sizeof(int));
    s = (int *)malloc(n * n * sizeof(int));

    printf("Enter %d dimentions: ", n + 1);
    for (i = 0; i < n + 1; i++)
        scanf("%d", &ar[i]);

    chain_mul(ar, mat, s, n + 1);
    printf("M: ");
    print_mat(mat, n);
    printf("S: ");
    print_mat(s, n);
    print_optimal(s, n, 0, n - 1);

    return 0;
}
/*
5
4 5 3 2 7 2

6
30 35 15 5 10 20 25

*/
