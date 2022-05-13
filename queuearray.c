#include <stdio.h>
#include <stdlib.h>
#define n 5

void enqueue();
void dequeue();
void isEmpty();
void isFull();
void print();

int elements[n], front = -1, rear = -1;

int main()
{
    int choice;
    while(choice != 4)
    {
        printf("\n*************************Main Menu*****************************\n");
        printf("\n=================================================================\n");
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice ?");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            print();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nEnter valid choice!!\n");
        }
    }
    /*dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    print();
    dequeue();
    print();*/
}

void isFull()
{
    if (rear==n)
    {
        printf("\nQueue is full!!");
    }
    else
    {
        printf("\nQueue is not full !!\n");
    }
}


void isEmpty()
{
    if (front== -1)
    {
        printf("\nQueue is empty");
    }
    else{
        printf("\nQueue is not empty\n");
    }
}

void enqueue(int value)
{
    if (rear==n)
    {
        printf("Queue is full!!");
    }
    else if(front == -1)
    {
        front=0;
        rear++;
        elements[rear]=value;
        printf("The inserted value is:%d\n",value);
    }
    else
    {
        printf("Queue is not full!!\n");
    }
}

void dequeue()
{
    if (front==-1)
    {
        printf("Queue is empty!!\n");
    }
    else if(rear == n)
    {
        front=0;
        front++;
        front = -1;
        rear = -1;
        printf("The deleted value is:%d\n",elements[front]);
    }
    else
    {
        printf("Queue is not full !!\n");
    }

}

void print()
{
    if (rear == -1){
        printf("\nQueue is Empty!!!\n");
    }else{
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  \n", elements[i]);
  }
}
