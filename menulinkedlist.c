#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node* insertion(struct node* head){
	if(head==NULL){
				int data;
				struct node *q=head;
				struct node* p;
				p=(struct node*)malloc(sizeof(struct node));
				printf("Enter the data:\n");
				scanf("%d",&data);
				p->data=data;
				p->next=q;
				return p;
			}
			else{
				printf("Where should the data be inserted:\n");
				int choice;
				printf("1.Begining\n");
				printf("2.At a index\n");
				printf("3.End\n");
				scanf("%d",&choice);
				if(choice==1){
					int data;
					//struct node* p=head;
					struct node* q;
					q=(struct node*)malloc(sizeof(struct node));
					printf("ENter the data be inserted");
					scanf("%d",&data);
					q->data=data;
					q->next=head;
					//printf("HEllo\n");
					return q;
				}
				else if(choice==2){
					printf("ENter the index and value to be added\n");
					int index,data;
					scanf("%d%d",&index,&data);
					struct node*p=head;
					struct node *q;
					q=(struct node*)malloc(sizeof(struct node));
					q->data=data;
					int i=0;
    				//struct node * p=head;
    				while(i!=index-1 && p->next!=NULL){
       					p=p->next;
        				i++;
    				}
					if(p->next==NULL){
						p->next=q;
						q->next=NULL;
					}
					else{
    					q->next=p->next;
    					p->next=q;
					}
    				return head;
				}
				else{
					int data;
					printf("ENter the data be inserted");
					scanf("%d",&data);
					struct node*p=head;
					struct node *q;
					q=(struct node*)malloc(sizeof(struct node));
					while(p->next!=NULL){
						p=p->next;
					}
					p->next=q;
					q->data=data;
					q->next=NULL;
					
					return head;
				}
			}
}

struct node* deletion(struct node * head){
	if(head==NULL){
		printf("The list is empty\n");
	}
	else{
		printf("Where should the data be deleted:\n");
			int choice;
			printf("1.Begining\n");
			printf("2.At a index\n");
			printf("3.End\n");
			scanf("%d",&choice);
			if(choice==1){
				head=head->next;
				return head;
			}
			else if(choice ==2){
				printf("ENter the index to be deleted\n");
				int index;
				scanf("%d",&index);
				struct node*p=head;
				struct node *q;
				q=head->next;
				//q=(struct node*)malloc(sizeof(struct node));
					
				while(index!=2){
					p=p->next;
					q=q->next;
					index--;
				}
				p->next=q->next;
				free(q);
				return head;
			}
			else{
				struct node*p=head;
				struct node *q;
				q=head->next;
				while(q->next!=NULL){
					p=p->next;
					q=q->next;
				}
				free(q);
				p->next=NULL;
				return head;
			}
	}
}

void search(struct node * head){
	if(head==NULL){
		printf("THE list is empty\n");
	}
	else{
		int i=1;
		printf("Enter the value to search:\n");
		int key;
		scanf("%d",&key);
		if(head->data!=key && head->next!=NULL){
			head=head->next;
			i++;
		}
		if(head->data!=key && head->next==NULL){
			printf("Element to found\n");
		}
		if(head->data==key){
			printf("The element %d is found at %d position\n",key,i);
		}
	}
}

void traverse(struct node * head){
	if(head==NULL){
		printf("THE list is empty\n");
	}
    else{
	    int i=0;
	    while(head!=NULL){
	    	printf("%d ",head->data);
	    	head=head->next;
	    	i++;
	    }
	    printf("\nThe number of elements in the linked list is %d \n",i);
    }
}

void reverse( struct node **head){
	if(*head==NULL){
		printf("The list is empty\n");
	}
	else{
	
		struct node* prev=NULL;
		struct node* next=NULL;
		struct node* curr=*head;
	
		while(curr!=NULL){
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
		}
		*head=prev;
	}
}

int main(){
	struct node* head = NULL;
/*	struct node* two;
	head=(struct node *)malloc(sizeof(struct node));
	two=(struct node *)malloc(sizeof(struct node));
	head->data=1;
	head->next=two;
	two->data=2;
	two->next=NULL;*/
	
	printf("MENU\n");
	printf("1.Insertion\n");
	printf("2.Deletion\n");
	printf("3.Search\n");
	printf("4.Traverse\n");
	printf("5.Reverse\n");
	printf("6.Exit\n");
	while(1){
		int choice;
		printf("Please enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:head=insertion(head);
					break;
			case 2:head=deletion(head);
					break;
			case 3:search(head);
					break;
			case 4:traverse(head);						
					break;
			case 5:reverse(&head);
					break;
			case 6:exit(0);
					break;			
			default:printf("ENter the correct value\n");
					break;			
		}
	}
	return 0;
}
