#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *Insert(struct node *head)
{
	if (head == NULL)
	{
		// printf("The list is empty\n");
		printf("ENter the data\n");
		int data;
		struct node *p = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &data);
		p->data = data;
		p->next = p;
		p->prev = p;

		return p;
	}
	else
	{
		printf("where should the data be inserted:\n");
		printf("1.begin\n");
		printf("2.At an index\n");
		printf("3.End\n");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("Enter the data to be inserted at begin:\n");
			int data;
			scanf("%d", &data);
			struct node *p = head;
			struct node *q;
			q = (struct node *)malloc(sizeof(struct node));
			q->data = data;
			q->next = p;
			q->prev = p->prev;
			
			if(p->next==p){
				p->next=q;
			}
			else{
			p->prev->next=q;
			}
			p->prev = q;

			return q;
		}
		else if (choice == 2)
		{
			int data, index;
			printf("Enter the data and index where should the data be inserted respectively:\n");
			scanf("%d%d", &data, &index);
			struct node *p = head;
			struct node *q;
			q = (struct node *)malloc(sizeof(struct node));
			while (index != 1)
			{
				p = p->next;
				index--;
			}
			q->data = data;
			q->next = p->next;
			p->next = q;
			q->prev = p;

			return head;
		}
		else
		{
			printf("Enter the data to be inserted at the end\n");
			int data;
			scanf("%d", &data);
			struct node *p = head;
			struct node *r = head;
			struct node *q;
			q = (struct node *)malloc(sizeof(struct node));
			q->data = data;
			while (p->next != r)
			{
				p = p->next;
			}
			//	printf("HELLO\n");
			q->prev = p;
			p->next = q;
			q->next = r;

			return r;
		}
	}
}

struct node *Deletion(struct node *head)
{
	if (head == NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		printf("Enter the where the data should be deleted\n");
		printf("1.begin\n");
		printf("2.At an index\n");
		printf("3.End\n");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
		{
			struct node *temp,*p=head;
    		temp = head;
   			 while (p->next != head)
    		{
        	p = p->next;
    		}
    		head = temp->next;
    		head->prev=p;
    		p->next=head;
    		temp->next = NULL;
   		 	free(temp);
    			return head;
		}			
			
		
		else if (choice == 2)
		{
			printf("ENter the index where the data should be deleted:");
			int index;
			scanf("%d", &index);
			struct node *p = head;
			struct node *q;
			q = (struct node *)malloc(sizeof(struct node));
			q = p->next;
			if (index == 1)
			{
				printf("please use delete at begin\n");
			}
			else
			{
				while (index != 2 && q->next != head)
				{
					p = p->next;
					q = q->next;
					index--;
				}
				if (q->next == head)
				{

					p->next = head;
					free(q);
					return head;
				}
				else
				{
					// q=p->next;
					q->prev = p;
					struct node *r;
					r = (struct node *)malloc(sizeof(struct node));
					r = q->next;
					r->prev = q;

					p->next = r;
					r->prev = p;
					free(q);
					return head;
				}
			}
		}
		else
		{
			struct node *p = head;
			struct node *q;
			q = (struct node *)malloc(sizeof(struct node));
			q = p->next;
			q->prev = p;
			while (q->next != head)
			{
				p = p->next;
				// q=q->next;
			}
			p->next = head;
			free(q);

			return head;
		}
	}
}

void Search(struct node *head)
{
	if (head == NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		printf("Enter the value to be found\n");
		int key;
		scanf("%d", &key);
		struct node *p = head;
		int i = 0;
		while (p->data != key && p->next != head)
		{
			p = p->next;
			i++;
		}
		if (p->next == head)
		{
			printf("Element not found\n");
		}
		else
		{
			printf("Element %d is found at %d postion\n", key, i);
		}
	}
}

void Traverse(struct node *head)
{
	if (head == NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		struct node *p = head;
		int i = 1;
		printf("%d ", p->data);
		p = p->next;
		while (p != head)
		{
			printf("%d ", p->data);
			p = p->next;
			i++;
		}
		printf("\n");
		printf("length of linked list is %d \n", i);
	}
}

void Reverse(struct node *head)
{
	if (head == NULL)
	{
		printf("The list is empty\n");
	}
	else
	{
		struct node *p = head;
		
		p=p->prev;
		while (p != head)
		{
			printf("%d ", p->data);
			p = p->prev;
		}
		printf("%d ",p->data);
		printf("\n");
	}
}

int main()
{
	struct node *head = NULL;
	// char a='YES';
	int x = 1;
	int choice;
	while (x == 1)
	{
		printf("MENU\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.search\n");
		printf("4.Traverse\n");
		printf("5.Reverse\n");
		// printf("6.Exit\n");

		printf("ENter choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			head = Insert(head);
			break;
		case 2:
			head = Deletion(head);
			break;
		case 3:
			Search(head);
			break;
		case 4:
			Traverse(head);
			break;
		case 5:
			Reverse(head);
			break;
		default:
			printf("please enter a valid number\n");
			break;
		}
		printf("Do u want to continue(binary):");
		// char cho;
		scanf("%d", &x);
	}
}
