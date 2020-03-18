#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int queue[MAX];
int rear=-1,front=-1;
void insert(int item);
int delete();
int peek();
int display();
int main()
{
    int choice ,item;
    while(1)
    {
        printf("1.Insert \n");
        printf("2.Delete \n");
        printf("3.Peek \n");
        printf("4.Display \n");
        printf("5.Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter data to be inserted: ");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            item=delete();
            printf("Deleted item :%d",item);
            printf("\n");
            break;
        case 3:
            printf("Top element is : %d",peek());
            printf("\n");
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice......\n");
        }
    }
}
void insert(int item)
{
    if(rear==MAX-1)
    {
        printf("Queue is full....");
    }
    if(front==-1)
    {
        front=0;
    }
    rear=rear+1;
    queue[rear]=item;
}
int delete()
{
    if(front==-1||front==rear+1)
    {
        printf("Queue is empty....");
    }
    int item;
    item=queue[front];
    front=front+1;
    return item;
}
int peek()
{
    if(front==-1||front==rear+1)
    {
        printf("Queue is empty....");
    }
    return  queue[front];
}
int display()
{
    int i;
    if(front==-1||front==rear+1)
    {
        printf("Queue is empty....");
    }
    for(i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
