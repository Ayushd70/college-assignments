#include <stdio.h>
#include <stdlib.h>
typedef struct linklist
{
    int data;
    struct linklist *next;
} node;

node *top, *temp, *ptr;
void push()
{
    temp = (node *)malloc(sizeof(node));
    printf("Enter the number ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (top == NULL)
        top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }
}
void pop()
{
    if (top == NULL)
        printf("\n U N D E R F L O W");
    else
    {
        printf("\n Deleted %d", top->data);
        top = top->next;
    }
}
void display()
{
    if (top == NULL)
        printf("\n Stack is Empty ");
    else
    {
        ptr = top;
        while (ptr != NULL)
        {
            printf("\n %d", ptr->data);
            ptr = ptr->next;
        }
    }
}
void main()
{
    int ch;
    top = NULL; // initialize
    while (1)   // infinite loop
    {
        printf("\n\n M E N U ");
        printf("\n----------------");
        printf("\n\n 1 for PUSH ");
        printf("\n 2 for POP");
        printf("\n 3 for DISPLAY");
        printf("\n 4 for EXIT ");
        printf("\n Enter the choice ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            display();
            break;

        case 2:
            pop();
            display();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(1);

        default:
            printf("\n wrong choice ");
        }
    }
}
