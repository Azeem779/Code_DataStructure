#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct noode *next;
}*front=NULL,*rear=NULL;
void insert(int item);
int delete();
int peek();
int display();
int main()
{
    int choice,item;
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
            printf("Deleted data is : %d",item);
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
            printf("Wrong choice.....\n");
        }
    }
}
void insert(int item)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;
    if(temp==NULL)
    {
        printf("Queue is full...");
    }
    if(front==NULL)
    {
        front=temp;
    }
    else
    {
        rear->next=temp;
    }
    rear=temp;
}
int delete()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue is empty");
    }
    int item;
    temp=front;
    item=temp->data;
    front=front->next;
    free(temp);
    return item;
}
int peek()
{
    if(front==NULL)
    {
        printf("Queue is empty...");
    }
    return front->data;
}
int display()
{
    struct node *temp;
    temp=front;
    if(front==NULL)
    {
        printf("Queue is empty...");
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
