#include<stdio.h>
#include<stdlib.h>
struct node
{
    int elements;
    struct node *next;
};
struct node *front;
struct node *rear;
void enqueue();
void dequeue();
void print();

void main()
{
    int choice;
    while(choice != 4)
    {
        printf("\n*************************Main Menu*****************************\n");
        printf("\n=================================================================\n");
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice ?");
        scanf("%d",& choice);
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
            printf("\nEnter valid choice??\n");
        }
    }
}
void enqueue()
{
    struct node *ptr;
    int item;

    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
       printf("Queue is full!!");
    }
    else
    {
        printf("\nEnter value?\n");
        scanf("%d",&item);
        ptr -> elements = item;
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
            front -> next = NULL;
            rear -> next = NULL;
        }
        else
        {
            rear -> next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void dequeue ()
{
    struct node *ptr;
    if(front == NULL)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        ptr = front;
        front = front -> next;
        free(ptr);
    }
}
void print()
{
    struct node *ptr;
    ptr = front;
    if(front == NULL)
    {
        printf("\nQueue is Empty!!!\n");
    }
    else
    {
        printf("\nQueue elements are:\n");
        while(ptr != NULL)
        {
            printf("\n%d\n",ptr -> elements);
            ptr = ptr -> next;
        }
    }
}
