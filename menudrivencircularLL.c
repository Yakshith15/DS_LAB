#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node * Insert(struct node* head){
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
        printf("WHere should the data be inserted:\n");
        printf("1.Begin\n");
        printf("2.At a index\n");
        printf("3.end\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1){
            printf("ENter the data to be inserted\n");
            int data;
            scanf("%d",&data);
            struct node*p=head;
            struct node *q;
            q=(struct node*)malloc(sizeof(struct node));
            q->data=data;
            while(p->next!=head){
                p=p->next;
            }
            p->next=q;
            q->next=head;
            
            return q;
        }
        else if(choice==2) {
            printf("Enter the data and the index where the data to be inserted\n");
            int data,index;
            scanf("%d%d",&data,&index);
            struct node*p=head;
            struct node *q;
            q=(struct node*)malloc(sizeof(struct node));
            q->data=data;
            while(index!=1){
                p=p->next;
                index--;
            }
            q->next=p->next;
            p->next=q;

            return head;
        }
        else{
            printf("ENter the data to be inserted\n");
            int data;
            scanf("%d",&data);
            struct node*p=head;
            struct node *q;
            q=(struct node*)malloc(sizeof(struct node));
            q->data=data;
            while(p->next!=head){
                p=p->next;
            }
            p->next=q;
            q->next=head;

            return head;
        }
    }
}

void Traverse(struct node* head){
    if(head==NULL){
        printf("LISt is empty");
    }
    else{
        struct node* p=head;
        do{
            printf("%d ",p->data);
            p=p->next;
        }
        while(p!=head );{
            printf("%d ",p->data);
            p=p->next;
        }
    
    }
}

int main(){
    struct node* head=NULL;
    printf("MENU\n");
    printf("1.Insertion\n");
    printf("2.traverse\n");
    printf("3.Exit\n");
    while(1){
        printf("ENter the choice:\n");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: head=Insert(head);
                    break;
            case 2: Traverse(head);
                    break;        
            case 3:exit(0);
                    break;   
            default:printf("ENter a valid num\n");
                    break;             
        }
    }

}