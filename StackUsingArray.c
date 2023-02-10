#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top==ptr->size-1){
       return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,int value){
    if(isFull(ptr)){
        printf("stack overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}

void pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack underflow\n");
        //return -1;
    }
    else{
        int var=ptr->arr[ptr->top];
        ptr->top--;
        printf("the value poped out is %d\n",var);
    }
}

void traverse(struct stack*s){
    if(s->top==-1){
        printf("Stack is empty\n");
    }
    else{
        while(s->top!=-1){
            printf("%d ",s->arr[s->top]);
            s->top--;
        }
    }
}

int main(){
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    printf("1-Insert into Stack\n2-Remove element from Stack\n3-Display elements in Stack\n4-Exit\n");
    while(1){
        printf("Enter the Option:"); 
        int choice;
        scanf("%d",&choice); 
        switch(choice){
            case 1:printf("Enter the value to be pushed\n");
                int data;
                scanf("%d",&data);
                push(s,data); 
            break;
            case 2:pop(s); 
            break;
            case 3:traverse(s); 
            break;
            case 4:exit(0); 
            break;
            default:printf("Enter the correct Option\n"); 
            break;
        }
    }
    return 0;
}