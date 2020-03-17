#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(item);
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
    if(top==MAX-1)
    {
        printf("Stack is full.");
    }
    top=top+1;
    stack[top]=item;
}
int pop()
{
    int item;
    if(top==-1)
    {
        printf("Stack is empty.");
        return 0;
    }
    item=stack[top];
    top=top-1;
    return item;
}
int peak()
{
    if(top==-1)
    {
        printf("Stack is empty.");
        return 0;
    }
    return stack[top];
}
int display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty.");
        return 0;
    }
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
