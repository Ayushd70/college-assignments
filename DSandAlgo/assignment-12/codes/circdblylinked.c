#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head, *ptr, *temp;
void insertion_beginning();
void insertion_last();
void deletion_beginning();
void deletion_last();
void display();
void search_and_delete();

int main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n***Main Menu*\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Create The Linked List\n2.Delete from Beginning\n3.Delete from last\n4.Search And Delete\n5.Show\n6.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            insertion_beginning();
            display();
            break;
        case 2:
            deletion_beginning();
            display();
            break;
        case 3:
            deletion_last();
            display();
            break;
        case 4:
            search_and_delete();
            display();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
void insertion_beginning()
{
    struct node *ptr, *temp;
    int item, i, j;
    printf("Enter No.Of Elements:");
    scanf("%d", &i);
    for (j = 1; j <= i; j++)
    {

        ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == NULL)
        {
            printf("\nOVERFLOW");
        }
        else
        {
            printf("\nEnter Item value:");
            scanf("%d", &item);
            ptr->data = item;
            if (head == NULL)
            {
                head = ptr;
                ptr->next = head;
                ptr->prev = head;
            }
            else
            {
                temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = ptr;
                ptr->prev = temp;
                head->prev = ptr;
                ptr->next = head;
                head = ptr;
            }
            printf("\nNode inserted\n");
        }
    }
}
void deletion_beginning()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }

    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        free(head);
        head = temp->next;
        printf("\nnode deleted\n");
    }
}
void deletion_last()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        head->prev = ptr->prev;
        ptr->prev->next = head;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        printf("\n printing values ... \n");

        while (ptr->next != head)
        {

            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

void search_and_delete()
{
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search and delete?\n");
        scanf("%d", &item);
        if (head->data == item)
        {
            printf("item found at location %d", i + 1);
            head = NULL;
            printf("\nnode deleted\n");
            flag = 0;
        }
        else
        {
            while (ptr->next != head)
            {
                if (ptr->data == item)
                {
                    printf("item found at location %d ", i + 1);
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                    printf("\nnode deleted\n");
                    flag = 0;
                    break;
                }

                else
                {
                    flag = 1;
                }
                i++;
                ptr = ptr->next;
            }
        }
        if (ptr->data = item)
        {
            printf("item found at location %d ", i + 1);
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            printf("\nnode deleted\n");
            flag = 0;
        }
        if (flag != 0)
        {
            printf("Item not found\n");
        }
    }
}