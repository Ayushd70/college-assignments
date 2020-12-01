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
    }
    else
    {
        ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = temp;
        temp->prev = ptr;
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

node *insertAfter(node *head, int key)
{
    node *ptr, *temp;
    int f = 0;

    if (head == NULL)
    {
        printf(" empty list ");
        return NULL;
    }
    else
    {
        if ((ptr = head)->data == key)
            f = 1;
        else
        {
            ptr = head->next;
            while (ptr != head)
            {
                if (ptr->data == key)
                {
                    f = 1;
                    break;
                }
                ptr = ptr->next;
            }
        }
        if (f == 1)
        {
            if (!(temp = (node *)malloc(sizeof(node))))
            {
                printf(" OUT OF MEMORY ");
                return NULL;
            }
            printf("Enter a number: ");
            scanf("%d", &temp->data);

            temp->next = ptr->next;
            temp->prev = ptr;
            ptr->next = temp;
            if (temp->next != NULL)
                temp->next->prev = temp;
            return temp;
        }
        else
        {
            printf(" not found");
            return NULL;
        }
    }
}

node *insertBefore(node **head, int key)
{
    node *ptr, *temp;
    int f = 0;

    if (*head == NULL)
    {
        printf(" empty list ");
        return NULL;
    }
    else
    {
        if ((ptr = *head)->data == key)
            f = 1;
        else
        {
            ptr = (*head)->next;
            while (ptr != *head)
            {
                if (ptr->data == key)
                {
                    f = 1;
                    break;
                }
                ptr = ptr->next;
            }
        }
        if (f == 1)
        {
            if (!(temp = (node *)malloc(sizeof(node))))
            {
                printf(" OUT OF MEMORY ");
                return NULL;
            }
            printf("Enter a number: ");
            scanf("%d", &temp->data);

            temp->next = ptr;
            temp->prev = ptr->prev;
            ptr->prev = temp;
            if (temp->prev != NULL)
                temp->prev->next = temp;
            else
                *head = temp;
            return temp;
        }
        else
        {
            printf(" not found");
            return NULL;
        }
    }
}

int deleteFirst(node **head)
{
    int f;
    node *temp;

    if (*head == NULL)
    {
        printf(" Empty List ");
        return NULL;
    }
    temp = *head;
    f = temp->data;

    *head = temp->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);

    return f;
}

int deleteLast(node **head)
{
    node *ptr, *temp;
    int f = 0;

    if (*head == NULL)
    {
        printf(" empty list ");
        return NULL;
    }
    else
    {
        ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;

        f = ptr->data;

        if (*head == ptr)
            *head = NULL;
        else
            ptr->prev->next = NULL;
        free(temp);
        return f;
    }
}

int deleteAfter(node *head, int key)
{
    node *ptr, *temp;
    int f = 0;

    if (head == NULL)
    {
        printf(" empty list ");
        return NULL;
    }
    else
    {
        if ((ptr = head)->data == key)
            f = 1;
        else
        {
            ptr = head->next;
            while (ptr != head)
            {
                if (ptr->data == key)
                {
                    f = 1;
                    break;
                }
                ptr = ptr->next;
            }
        }
        if (f == 1)
        {
            if (ptr->next == NULL)
            {
                printf("not possible");
                return NULL;
            }
            temp = ptr->next;
            f = temp->data;

            ptr->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = ptr;
            free(temp);
            return f;
        }
        else
        {
            printf(" not found");
            return NULL;
        }
    }
}

int deleteBefore(node **head, int key)
{
    node *ptr, *temp;
    int f = 0;

    if (*head == NULL)
    {
        printf(" empty list ");
        return NULL;
    }
    else
    {
        if ((ptr = *head)->data == key)
            f = 1;
        else
        {
            ptr = (*head)->next;
            while (ptr != *head)
            {
                if (ptr->data == key)
                {
                    f = 1;
                    break;
                }
                ptr = ptr->next;
            }
        }
        if (f == 1)
        {
            if (ptr->prev == NULL)
            {
                printf("not possible");
                return NULL;
            }
            temp = ptr->prev;
            f = temp->data;

            ptr->prev = temp->prev;
            if (temp->prev != NULL)
                temp->prev->next = ptr;
            else
                *head = ptr;
            free(temp);
            return f;
        }
        else
        {
            printf(" not found");
            return NULL;
        }
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
    for (ptr = head; ptr != NULL; ptr = ptr->next)
        printf(" %d", ptr->data);
}

int main()
{
    node *head = NULL;
    int c, num, pos;

    while (1)
    {
        printf("\n1. Create list\n2. Insert After\n3. Insert Before\n4. Delete First\n5. Delete Last\n6. Delete After\n7. Delete Before\n8. Display\n0. Exit");
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
            insertAfter(head, num);
            display(head);
            break;
        case 3:
            printf("Enter the key: ");
            scanf("%d", &num);
            insertBefore(&head, num);
            display(head);
            break;
        case 4:
            deleteFirst(&head);
            display(head);
            break;
        case 5:
            deleteLast(&head);
            display(head);
            break;
        case 6:
            printf("Enter the key: ");
            scanf("%d", &num);
            deleteAfter(head, num);
            display(head);
            break;
        case 7:
            printf("Enter the key: ");
            scanf("%d", &num);
            deleteBefore(&head, num);
            display(head);
            break;
        case 8:
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