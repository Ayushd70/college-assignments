#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int top; // global variable it can be access any where of the program
void push(int stk[])
{
    int num;
    if (top == MAX - 1)
        printf("\n O V E R F L O W ");
    else
    {
        printf("Enter the number ");
        scanf("%d", &num);
        stk[++top] = num; // place the number at stack top
    }
}
void pop(int stk[])
{
    if (top == -1)
        printf("\n U N D E R F L O W");
    else
    {
        printf("\n Deleted %d", stk[top--]);
    }
}
void show(int stk[])
{
    int i;
    if (top == -1)
        printf("\n Stack is Empty");
    else
    {
        for (i = top; i >= 0; i--)
            printf("\n %d", stk[i]);
    }
}
void main()
{
    int s[MAX], ch;
    top = -1; // initialize
    while (1) // inifinite loop
    {
        printf("\n\n M E N U ");
        printf("\n----------------");
        printf("\n 1 for PUSH");
        printf("\n 2 for POP ");
        printf("\n 3 for DISPLAY");
        printf("\n 4 for EXIT ");
        printf("\n Enter the choice ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push(s);
            show(s);
            break;

        case 2:
            pop(s);
            show(s);
            break;

        case 3:
            show(s);
            break;

        case 4:
            exit(1);

        default:
            printf("\n Wrong choice ");
        }
    }
}
