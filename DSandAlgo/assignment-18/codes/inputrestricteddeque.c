#include <stdio.h>
#include <stdlib.h>

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
void enqueueR(lLQueue *q)
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

void dequeueF(lLQueue *q)
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
        {
            q->front = q->front->link; // move to the next node
        }
    }
}
void dequeueR(lLQueue *q)
{
    nd *ptr;
    if (q->front == NULL)
        printf("\n U N D E R F L O W");
    else
    {
        printf("\n Deleted %d", q->rear->data);
        if (q->front == q->rear) // single element
        {
            q->front = NULL;
            q->rear = NULL;
        }
        else
        {
            ptr = q->front;
            while (ptr->link != q->rear)
                ptr = ptr->link;
            q->rear = ptr;
            ptr->link = NULL;
        }
    }
}
void display(lLQueue *q)
{
    nd *ptr;
    if (q->front == NULL)
        printf("\n Queue is Empty");
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

/*------------------------------------------------------------------*/
void main()
{
    int ch;
    lLQueue *Q;
    Q = createLLQueue();
    while (1)
    {
        printf("\n\n M E N U ");
        printf("----------------");
        printf("\n 1 for ENQUEUE(rear)  ");
        printf("\n 2 for DEQUEUE(front) ");
        printf("\n 3 for DEQUEUE(rear) ");
        printf("\n 4 for DISPLAY ");
        printf("\n 5 for Exit ");
        printf("\n Enter the choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueueR(Q);
            display(Q);
            break;

        case 2:
            dequeueF(Q);
            display(Q);
            break;

        case 3:
            dequeueR(Q);
            display(Q);
            break;

        case 4:
            display(Q);
            break;

        case 5:
            exit(1);

        default:
            printf("\n Oops! Wrong choice ");
        }
    }

} // end of main
