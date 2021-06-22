#define N 15
#include <stdbool.h>
#include <stdio.h>
int d = 0;
int n;
void printSolution(int board[N][N])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf(" %c ", (board[i][j]) ? 'Q' : '-');
        printf("\n");
    }
    printf("Solution set: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (board[i][j])
                printf(" %d ", j + 1);
    }
    printf("\n\n");
}
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}
bool solveNQUtil(int board[N][N], int col)
{
    int i;
    if (col >= n)
        printSolution(board), d++;

    for (i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                printSolution(board), d++;

            board[i][col] = 0;
        }
    }

    return false;
}
bool solveNQ()
{
    int board[N][N], i, l;
    for (i = 0; i < n; i++)
        for (l = 0; l < n; l++)
            board[i][l] = 0;
    solveNQUtil(board, 0);
    if (d == 0)
    {
        printf("Solution does not exist");
        return false;
    }
    return true;
}
int main()
{
    printf("\n Enter no. of queen: ");
    scanf("%d", &n);
    solveNQ();
    printf("Total number of solution: %d ", d);
    return 0;
}
