#include<stdio.h>
#define max 100
int queue[max];
int front =-1;
int rear=-1;
void enqueue(int element)
{
    if(front==-1 && rear==-1)//condition to check if queue is empty
    {
        front =0;
        rear=0;
        queue[rear]=element;
    }
    else if((rear+1)%max==front)
    {
        printf("queue is full\n");
    }
    else
    {
        rear=(rear+1)%max;
        queue[rear]=element;
    }
}


int dequeue(){
    if(front==-1 && rear==-1)
    {
        printf("queue is underflow\n");
    }

    else if(front==rear){
    
    printf("the element dequeued is %d",queue[front]);
    front=-1;
    rear=-1;
    }
    else
    {
        printf("the dequeued element is %d",queue[front]);
        front=(front+1)%max;
    }

}

void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("the elements in queue are:\n");
        while(i<=rear)
        {
            printf("%d\t",queue[i]);
            i=(i+1)%max;
        }
    }
}

int main()
{
    int choice=1,x;

    while(choice<4 && choice!=0)
    {
        printf("\n 1. press insert an element");
        printf("\n 2.press to delete an element");
        printf("\n 3.press to display the queue");
        printf("\n enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1: printf("enter the element you want to be inserted");
                scanf("%d",&x);
                enqueue(x);
                break;
        case 2: dequeue();
                break;
        case 3:display();
                break;
        }
    }

        
        
    
    return 0;
}