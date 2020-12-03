#include <stdlib.h>
#include <stdio.h>

typedef struct doublyLinkedList
{
    int data;
    struct doublyLinkedList *prev;
    struct doublyLinkedList *next;
} node;

node *insertLast(node **head, int data)
{
    node *ptr, *temp;

    if (!(temp = (node *)malloc(sizeof(node))))
    {
        printf(" OUT OF MEMORY ");
        return NULL;
    }

    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (*head == NULL)
    {
        *head = temp;
        temp->next = *head;
        temp->prev = *head;
    }
    else
    {
        temp->next = *head;
        temp->prev = (*head)->prev;

        temp->prev->next = temp;
        (*head)->prev = temp;
    }

    return temp;
}

node *insertFirst(node **head, int data)
{
    node *ptr, *temp;

    if (!(temp = (node *)malloc(sizeof(node))))
    {
        printf(" OUT OF MEMORY ");
        return NULL;
    }

    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    if (*head == NULL)
    {
        *head = temp;
        temp->next = *head;
        temp->prev = *head;
    }
    else
    {
        temp->next = *head;
        temp->prev = (*head)->prev;

        temp->prev->next = temp;
        (*head)->prev = temp;

        *head = temp;
    }

    return temp;
}

void createDList(node **head, int size)
{
    int i, num;
    printf("Enter %d number: ", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &num);
        insertLast(head, num);
    }
}

void display(node *head)
{
    node *ptr;

    if (head == NULL)
    {
        printf("\nList: empty");
        return;
    }

    printf("\nList:");
    printf(" %d", head->data);
    for (ptr = head->next; ptr != head; ptr = ptr->next)
        printf(" %d", ptr->data);
}

int main()
{
    node *head = NULL;
    int c, num, pos;

    printf("====================L I N K E D   L I S T============================");
    while (1)
    {
        printf("\n1. Create list\n2. Insert First\n3. Insert Last\n4. Display\n0. Exit");
        display(head);
        printf("\n\nEnter: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the size: ");
            scanf("%d", &num);
            createDList(&head, num);
            display(head);
            break;
        case 2:
            printf("Enter the key: ");
            scanf("%d", &num);
            insertFirst(&head, num);
            display(head);
            break;
        case 3:
            printf("Enter the key: ");
            scanf("%d", &num);
            insertLast(&head, num);
            display(head);
            break;
        case 4:
            display(head);
            break;
        case 0:
            exit(0);
        default:
            printf(" Wrong Input ");
        }
    }

    return 0;
}