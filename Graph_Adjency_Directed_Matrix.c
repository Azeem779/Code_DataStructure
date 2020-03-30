#include<stdio.h>
#define MAX 100
int adj[MAX][MAX];
void create_graph();
int n;
void insert(int origin,int destination);
void delete(int origin,int destination);
void display();
int main()
{
    int choice,origin,destination;
    create_graph();
    while(1)
    {
        printf("\n1.Insert the edge : ");
        printf("\n2.Delete the edge : ");
        printf("\n3.Display : ");
        printf("\n4.Exit : ");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the edege to be inserted : ");
            scanf("%d %d",&origin,&destination);
            insert(origin,destination);
            break;
        case 2:
            printf("Enter the edges to be deleted : ");
            scanf("%d %d",&origin,&destination);
            delete(origin,destination);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice..");
            printf("\n");
        }
    }
}
void create_graph()
{
    int i,j,max,n,origin,destination;
    printf("Enter the vertices : ");
    scanf("%d",&n);
    max=n*(n-1);
    for(i=1;i<=max;i++)
    {
        printf("Enter edges %d(-1 -1 to quit) : ",i);
        scanf("%d %d",&origin,&destination);
    if(origin==-1 && destination==-1)
    {
        break;
    }
    if(destination>n||origin>n||origin<=0||destination<=0)
    {
        printf("invalid edge.\n");
        i--;
    }
    else
    {
        adj[origin][destination]=1;
    }
    }
}
void insert(int origin,int destination)
{
    if(origin<=0||origin>n)
    {
        printf("Origin vertex does not exist.\n");
        return;
    }
     if(destination<=0||destination>n)
    {
        printf("Destination vertex does not exist.\n");
        return;
    }
    adj[origin][destination]=1;
}
void delete(int origin,int destination)
{
    if(origin<=0||origin>n||destination<=0||destination>n||adj[origin][destination]==0)
    {
        printf("This edge does not exist.\n");
        return;
    }
    adj[origin][destination]=0;
}
void display()
{
    int i,j;
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
           printf("%4d",adj[i][j]);
       }
       printf("\n");
    }
}

