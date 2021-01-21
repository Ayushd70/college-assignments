#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/*-----------------------------------------------------------*/
// implement Linear Queue
typedef struct arrQueue
{
    int front; // for deletion
    int rear;  // for insertion
    int *Q;
} arrQueue;
arrQueue *createArrQueue(int maxLen)
{
    arrQueue *qu = (arrQueue *)malloc(sizeof(arrQueue));
    qu->Q = (int *)malloc(maxLen * sizeof(int));
    qu->front = -1;
    qu->rear = -1;
    return qu;
}
void aInsert(arrQueue *q)
{
    int num;
    if (q->rear == MAX - 1)
        printf("\n Queue is Full ");
    else
    {
        printf("Enter the number ");
        scanf("%d", &num); // accept number from user

        if (q->rear == -1) // queue is empty
        {
            q->front = 0;
            q->rear = 0;
            q->Q[q->rear] = num; // place the number at first
        }
        else
        {
            q->rear = q->rear + 1;
            q->Q[q->rear] = num; // place the number
        }
    }
}
void aDelete(arrQueue *q)
{
    if (q->front == -1)
        printf("\n Queue is Empty");
    else
    {
        printf("\n Deleted %d", q->Q[q->front]);
        if (q->rear == q->front) // single element
        {
            q->front = -1;
            q->rear = -1;
        }
        else
            q->front = q->front + 1;
    }
}
void aDisplay(arrQueue *q)
{
    int i;
    if (q->front == -1)
        printf("\n\n Nothing To Display");
    else
    {
        for (i = q->front; i <= q->rear; i++)
        {
            printf("\n %d", q->Q[i]);
        }
    }
}
/*-----------------------------------------------------------------*/
typedef struct node
{
    int data;          //store actual data
    struct node *link; // hold the address of next node
} nd;
typedef struct lLQueue
{
    nd *front;
    nd *rear;

} lLQueue;
lLQueue *createLLQueue()
{
    lLQueue *qu = (lLQueue *)malloc(sizeof(lLQueue));
    qu->front = NULL;
    qu->rear = NULL;
    return qu;
}
void Insert(lLQueue *q)
{
    nd *temp = (nd *)malloc(sizeof(nd));
    printf("Enter the data : ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (q->rear == NULL) // list is empty
    {
        q->front = temp;
        q->rear = temp;
    }
    else
    {
        q->rear->link = temp;
        q->rear = temp;
    }
}

void Delete(lLQueue *q)
{

    if (q->front == NULL)
        printf("\n U N D E R F L O W");
    else
    {
        printf("\n Deleted %d", q->front->data);
        if (q->front == q->rear) // single element
        {
            q->front = NULL;
            q->rear = NULL;
        }
        else
            q->front = q->front->link; // move to the next node
    }
}
void display(lLQueue *q)
{
    nd *ptr;
    if (q->front == NULL)
        printf("\n List is Empty");
    else
    {
        ptr = q->front;
        while (ptr != NULL)
        {
            printf("\n %d", ptr->data);
            ptr = ptr->link; // move to the next node
        }
    }
}
typedef union queue
{
    lLQueue *lQ;
    arrQueue *aQ;
} queue;

/*------------------------------------------------------------------*/
void main()
{
    int ch;
    /*lLQueue *Q;
    arrQueue *Q; // declare queue*/
    queue Q;

    printf("1.Queue using Array\n2.Queue using Linked List\n\nEnter: ");
    scanf("%d", &ch);
    if (ch == 2)
    {
        Q.lQ = createLLQueue();
        while (1)
        {
            printf("\n\n M E N U ");
            printf("----------------");
            printf("\n 1 for Insert  ");
            printf("\n 2 for Delete ");
            printf("\n 3 for Display ");
            printf("\n 4 for Exit ");
            printf("\n Enter the choice ");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                Insert(Q.lQ);
                display(Q.lQ);
                break;

            case 2:
                Delete(Q.lQ);
                display(Q.lQ);
                break;

            case 3:
                display(Q.lQ);
                break;

            case 4:
                exit(1);

            default:
                printf("\n Oops! Wrong choice ");
            }
        }
    }
    else if (ch == 1)
    {
        Q.aQ = createArrQueue(MAX);
        while (1)
        {
            printf("\n\n M E N U ");
            printf("\n------------------");
            printf("\n 1 for Insert ");
            printf("\n 2 for Delete ");
            printf("\n 3 for Display ");
            printf("\n 4 for Exit ");
            printf("\n\n Enter Choice ");
            scanf("%d", &ch);

            switch (ch)
            {
            case 1:
                aInsert(Q.aQ);
                aDisplay(Q.aQ);
                break;

            case 2:
                aDelete(Q.aQ);
                aDisplay(Q.aQ);
                break;

            case 3:
                aDisplay(Q.aQ);
                break;

            case 4:
                exit(1);

            default:
                printf("\n Wrong choice ");
            } // end of switch
        }     // end of while
    }
    else
        printf("Bad choise");
} // end of main