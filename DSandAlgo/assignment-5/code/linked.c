#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct link *start = NULL;
void insertfront();
void insertend();
void insertn();
void count();
void display();
void insertfront()
{
	int x;
	struct node *new = (struct node *)malloc(sizeof(struct node));
	printf("Enter the New Value =");
	scanf("%d", &x);
	new->data = x;
	new->link = NULL;
	if (start == NULL)
	{
		start = new;
	}
	else
	{
		new->link = start;
		start = new;
	}
	printf("Final List =");
	display();
}
void insertend()
{
	struct node *t;
	int x;
	struct node *new = (struct node *)malloc(sizeof(struct node));
	printf("Enter the Data =");
	scanf("%d", &x);
	new->data = x;
	new->link = NULL;

	if (start == NULL)
	{
		start = new;
	}
	else
	{
		t = start;
		while (t->link != NULL)
		{
			t = t->link;
		}
		t->link = new;
	}
	printf("Final List =");
	display();
}
void insertn()
{
	struct node *new, *t;
	int x, pos, i = 1;
	new = (struct node *)malloc(sizeof(struct node));
	printf("\n\nEnter the Number =");
	scanf("%d", &x);
	new->data = x;
	new->link = NULL;
	if (start == NULL)
	{
		start = new;
	}
	else
	{
		printf("Enter the Position =");
		scanf("%d", &pos);
		if (pos == 1)
		{
			insertfront();
		}
		else
		{

			t = start;
			while (i + 1 != pos)
			{
				t = t->link;
				if (t == NULL)
				{
					printf("The Given Position is Not Found\n");
					return;
				}
				i++;
			}
			new->link = t->link;
			t->link = new;
		}
	}
	printf("Final List =");
	display();
}
void count()
{
	struct node *c;
	int c1 = 0;
	if (start == NULL)
	{
		printf("Empty");
	}
	else
	{
		c = start;
		while (c != NULL)
		{
			c1++;
			c = c->link;
		}
		printf("No of Elements %d", c1);
	}
	printf("\nFinal List =");
	display();
}
void display()
{
	struct node *t;
	if (start == NULL)
	{
		printf("Empty");
	}
	else
	{
		t = start;
		while (t != NULL)
		{
			printf("\t%d", t->data);
			t = t->link;
		}
	}
}
void main()
{
	int choice;
	do
	{
		printf("\n\n1)Enter from Front \n2)Enter from End \n3)Enter in nth Position");
		printf("\n4)Count the Number of Link \n5)Display Elements \n6)Exit\n->");
		scanf("%d", &choice);
		if (choice == 1)
			insertfront();
		else if (choice == 2)
			insertend();
		else if (choice == 3)
			insertn();
		else if (choice == 4)
			count();
		else
			display();
	} while (choice <= 5);
}
