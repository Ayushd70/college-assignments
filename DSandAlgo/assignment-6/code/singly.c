#include <stdlib.h>
#include <stdio.h>

typedef struct linkedList
{
    int data;
    struct linkedList *link;
} node;

node *insert(node **head, int data)
{
    node *temp;

    if (!(temp = (node *)malloc(sizeof(node))))
    {
        printf(" OUT OF MEMORY ");
        return NULL;
    }

    temp->data = data;
    temp->link = *head;
    *head = temp;

    return temp;
}

void display(node *head)
{
    node *ptr;

    if (head == NULL)
    {
        printf(" List is empty");
        return;
    }

    printf("\nList:");
    for (ptr = head; ptr != NULL; ptr = ptr->link)
        printf(" %d", ptr->data);
}

int deleteFront(node **head)
{
    node *ptr;
    int data;
    if (*head == NULL)
    {
        printf(" U N D E R F L O W ");
        return -1;
    }

    ptr = *head;
    *head = (*head)->link;

    data = ptr->data;
    free(ptr);
    return data;
}

int deleteLast(node **head)
{
    node *ptr, *last;
    int data;
    if (*head == NULL)
    {
        printf(" U N D E R F L O W ");
        return -1;
    }

    last = *head;
    if ((*head)->link == NULL)
        *head = NULL;
    else
    {
        ptr = *head;
        while (ptr->link->link != NULL)
            ptr = ptr->link;
        last = ptr->link;
        ptr->link = NULL;
    }
    data = last->data;
    free(last);
    return data;
}

node *search(node *head, int key)
{
    node *ptr, *res = NULL;

    if (head != NULL)
    {
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                res = ptr;
                break;
            }
            ptr = ptr->link;
        }
    }

    return res;
}

int deleteAfter(node *head, int key)
{
    node *ptr, *loc;
    int data;

    loc = search(head, key);
    if (loc == NULL)
    {
        printf(" NOT FOUND ");
        return -1;
    }
    if (loc->link == NULL)
    {
        printf(" UNSUCCESSFUL ");
        return -1;
    }

    ptr = loc->link;
    loc->link = ptr->link;

    data = ptr->data;
    free(ptr);
    return data;
}

int deleteBefore(node **head, int key)
{
    node *ptr, *loc, *old;
    int data;

    loc = search(*head, key);
    if (loc == NULL)
    {
        printf(" NOT FOUND ");
        return -1;
    }
    if (*head == loc)
    {
        printf(" UNSUCCESSFUL ");
        return -1;
    }

    if ((*head)->link == loc)
    {
        old = *head;
        *head = loc;
    }
    else
    {
        ptr = *head;
        while (ptr->link->link != loc)
            ptr = ptr->link;
        old = ptr->link;
        ptr->link = old->link;
    }

    data = old->data;
    free(old);
    return data;
}

int main()
{
    node *head = NULL;
    int c, num, pos;

    while (1)
    {
        printf("\n1. Insert \n2. Delete First \n3. Delete Last\n4. Delete After\n5. Delete Before\
		\n6. Search\n7. Display\n0. Exit\n\nEnter: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &num);
            insert(&head, num);
            break;
        case 2:
            deleteFront(&head);
            break;
        case 3:
            deleteLast(&head);
            break;
        case 4:
            printf("Delete after(key): ");
            scanf("%d", &pos);
            deleteAfter(head, pos);
            break;
        case 5:
            printf("Delete before(key): ");
            scanf("%d", &pos);
            deleteBefore(&head, pos);
            break;
        case 6:
            printf("Search key: ");
            scanf("%d", &pos);
            if (search(head, pos))
                printf(" Match Found ");
            else
                printf(" Match Not Found ");
            break;
        case 7:
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
