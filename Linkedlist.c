//linked lists traversal, insertions at begin, any index, end
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

//Traversing the list
void LinkedListTraverse(struct node * ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

//Inserting a element at the begining of the linked list
struct node * InsertAtBegin(struct node *head,int data){
    struct node * ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;

    return ptr;
}

//Inserting a element at a particular index of the linked list
struct node * InsertAtIndex(struct node* head,int data,int index){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    int i=0;
    struct node * p=head;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;

    return head;
}

struct node * InsertAtEnd(struct node * head,int data){
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;

    return head;
}


int main(){
    struct node *head;
    struct node *two;
    struct node *three;

    head=(struct node*)malloc(sizeof(struct node));
    two=(struct node*)malloc(sizeof(struct node));
    three=(struct node*)malloc(sizeof(struct node));

    head->data=1;
    head->next=two;

    two->data=2;
    two->next=three;

    three->data=3;
    three->next=NULL;

    LinkedListTraverse(head);
    //printf("\nAfter Insertion at the begining\n");
    //head=InsertAtBegin(head,34);
    //printf("\nAfter inserting at a particular index:\n");
    //head=InsertAtIndex(head,15,2);
    printf("\n After inserting at the end:\n");
    head=InsertAtEnd(head,11);
    LinkedListTraverse(head);

    return 0;
}
