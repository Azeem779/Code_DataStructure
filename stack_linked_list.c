#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
}*top=NULL;
void push(int item);
int pop();
int peak();
int display();
int main()
{
    int choice,item;
    while(1)
    {
        printf("1.Push data.\n");
        printf("2.Pop data.\n");
        printf("3.Peak data.\n");
        printf("4.Display data.\n");
        printf("5.Exit.\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter data to be inserted: ");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            item=pop();
            printf("Popped item is :%d",item);
            printf("\n");
            break;
        case 3:
            printf("Top element of the stack is :%d",peak());
            printf("\n");
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice........\n");
        }
    }
}
void push(int item)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Stack is full.");
    }
    temp->data=item;
    temp->link=top;
    top=temp;
}
int pop()
{
    int item;
    struct node *p;
    if(top==NULL)
    {
        printf("Stack is empty.");
        return 0;
    }
    p=top;
    item=p->data;
    top=top->link;
    free(p);
    return item;
}
int peak()
{
    struct node *p;
    if(top==NULL)
    {
        printf("Stack is empty.");
        return 0;
    }
    return top->data;
}
int display()
{
    struct node *p;
    if(top==NULL)
    {
        printf("Stack is empty.");
    }
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
}
