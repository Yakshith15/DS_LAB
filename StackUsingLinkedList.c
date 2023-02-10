#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node* prev;
};

struct node* insertion(struct node*top){
    printf("enter the data\n");
    int data;
    scanf("%d",&data);
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->prev=top;

    return p;
}

struct node* deletion(struct node * top){
    if(top==NULL){
        printf("stack underflow");
    }
    else{
    printf("the data poped is:");
    printf("%d ",top->data);
    struct node*p=top;
    p=p->prev;
    return p;
}
}

void traverse(struct node* top){
    if(top==NULL){
        printf("The stack is empty\n");
    }
    else{
        struct node*p=top;
        while(p!=NULL){
            printf("%d ",p->data);
            p=p->prev;
        }
    }

}

int main(){
    struct node *top;
    top=NULL;
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.traverse\n");
    printf("4.exit\n");
    while(1){
        printf("Enter ur choice\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:top=insertion(top);
                    break;
            case 2:top=deletion(top);
                    break;
            case 3:traverse(top);
            break;
            case 4:exit(0);
            break;
            default:printf("Enter crct value\n");
            break;                
        }
    }
}

