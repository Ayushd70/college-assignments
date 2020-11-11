#include <stdlib.h>
#include <stdio.h>

typedef struct linkedList
{
	int data;
	struct linkedList *link;
} node;

node *insertLast(node **head, int data)
{
	node *ptr, *temp;

	if (!(temp = (node *)malloc(sizeof(node))))
	{
		printf("OUT OF MEMORY");
		return NULL;
	}

	temp->data = data;
	temp->link = NULL;
	if (*head == NULL)
	{
		*head = temp;
		temp->link = *head;
	}
	else
	{
		ptr = *head;
		while (ptr->link != *head)
			ptr = ptr->link;

		ptr->link = temp;
		temp->link = *head;
	}

	return temp;
}
void createList(node **head)
{
	node *ptr;
	int n, i, a;
	printf("Enter the no. of elements ");
	scanf("%d", &n);
	printf("\nEnter %d element: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (!insertLast(head, a))
			break;
	}
}

node *insertAfter(node *head, int key)
{
	node *ptr, *temp;
	int f = 0;

	if (head == NULL)
	{
		printf("empty list");
		return NULL;
	}
	else
	{
		if ((ptr = head)->data == key)
			f = 1;
		else
		{
			ptr = head->link;
			while (ptr != head)
			{
				if (ptr->data == key)
				{
					f = 1;
					break;
				}
				ptr = ptr->link;
			}
		}
		if (f == 1)
		{
			if (!(temp = (node *)malloc(sizeof(node))))
			{
				printf("OUT OF MEMORY");
				return NULL;
			}
			printf("Enter a number: ");
			scanf("%d", &temp->data);

			temp->link = ptr->link;
			ptr->link = temp;
			return temp;
		}
		else
		{
			printf("not found");
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
		printf("empty list");
		return NULL;
	}
	else if ((ptr = *head)->data == key)
	{
		if (!(temp = (node *)malloc(sizeof(node))))
		{
			printf("OUT OF MEMORY");
			return NULL;
		}
		printf("Enter a number: ");
		scanf("%d", &temp->data);

		temp->link = *head;
		while (ptr->link != *head)
			ptr = ptr->link;
		ptr->link = temp;
		*head = temp;
		return temp;
	}
	else if ((*head)->link != *head)
	{
		ptr = *head;
		while (ptr->link != *head)
		{
			if (ptr->link->data == key)
			{
				f = 1;
				break;
			}
			ptr = ptr->link;
		}

		if (f == 1)
		{
			if (!(temp = (node *)malloc(sizeof(node))))
			{
				printf("OUT OF MEMORY");
				return NULL;
			}
			printf("Enter a number: ");
			scanf("%d", &temp->data);

			temp->link = ptr->link;
			ptr->link = temp;
			return temp;
		}
		else
		{
			printf("not found");
			return NULL;
		}
	}
}

int deleteAfter(node *head, int key)
{
	node *ptr, *temp;
	int f = 0;

	if (head == NULL)
	{
		printf("empty list ");
		return NULL;
	}
	else
	{
		if ((ptr = head)->data == key)
			f = 1;
		else
		{
			ptr = head->link;
			while (ptr != head)
			{
				if (ptr->data == key)
				{
					f = 1;
					break;
				}
				ptr = ptr->link;
			}
		}
		if (f == 1)
		{
			if (ptr->link == head)
			{
				printf("not possible");
				return NULL;
			}
			temp = ptr->link;
			f = temp->data;

			ptr->link = ptr->link->link;
			free(temp);
			return f;
		}
		else
		{
			printf("not found");
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
		printf("empty list ");
		return NULL;
	}
	else if ((ptr = *head)->data == key)
	{
		printf("not possible");
		return NULL;
	}
	else if ((ptr = *head)->link->data == key)
	{
		ptr = *head;
		while (ptr->link != *head)
			ptr = ptr->link;
		ptr->link = (*head)->link;
		f = (*head)->data;
		free(*head);
		*head = ptr->link;
		return f;
	}
	else if ((*head)->link->link != *head)
	{
		ptr = *head;
		while (ptr->link->link != *head)
		{
			if (ptr->link->link->data == key)
			{
				f = 1;
				break;
			}
			ptr = ptr->link;
		}

		if (f == 1)
		{
			temp = ptr->link;
			f = temp->data;

			ptr->link = ptr->link->link;
			free(temp);
			return temp;
		}
		else
		{
			printf("not found");
			return NULL;
		}
	}
}

void display(node *head)
{
	node *ptr;

	if (head == NULL)
	{
		printf("List is empty");
		return;
	}

	printf("\nList:");
	for (ptr = head; ptr->link != head; ptr = ptr->link)
		printf(" %d", ptr->data);
	printf(" %d", ptr->data);
}
int main()
{
	node *head = NULL;
	int c, num, pos;

	while (1)
	{
		printf("\n1. Create List\n2. Insert After\n3. Insert Before\n4. Delete After\n5. Delete Before\n6. Display\n0. Exit\n\nEnter: ");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			createList(&head);
			display(head);
			break;
		case 2:
			printf("Enter the key: ");
			scanf("%d", &num);
			insertAfter(head, num);
			display(head);
			break;
		case 3:
			printf("Enter a key: ");
			scanf("%d", &num);
			insertBefore(&head, num);
			display(head);
			break;
		case 4:
			printf("Enter a key: ");
			scanf("%d", &num);
			deleteAfter(head, num);
			display(head);
			break;
		case 5:
			printf("Enter a key: ");
			scanf("%d", &num);
			deleteBefore(&head, num);
			display(head);
			break;
		case 6:
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