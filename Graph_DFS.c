#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define visited 2
int state[MAX];
int n;
int adj[MAX][MAX];
int stack[MAX];
int top=-1;
void create_graph();
void df_traversal();
void dfs(int v);
void push(int v);
int pop();
int isempty();
main()
{
    create_graph();
    df_traversal();
}
void df_traversal()
{
    int v;
    for(v=0;v<n;v++)
        state[v]=initial;
    printf("Enter the stating vertex for DFS : ");
    scanf("%d",&v);
    dfs(v);
}
void dfs(int v)
{
    int i;
    push(v);
    while(!isempty())
    {
        v=pop();
        if(state[v]==initial)
        {
            printf("%d ",v);
            state[v]=visited;
        }
        for(i=n-1;i>=0;i--)
        {
            if(adj[v][i]==1 && state[i]==initial)
            {
                push(i);
            }
        }
    }
}
void push(int v)
{
    if(top==(MAX-1))
    {
        printf("Overflow.\n");
        return ;
    }
        top=top+1;
        stack[top]=v;
}
int pop()
{
    int v;
    if(top==-1)
    {
        printf("Underflow.\n");
        exit(1) ;
    }
    v=stack[top];
    top=top-1;
    return v;
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void create_graph()
{
    int ori,des,max,i;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    max=n*(n-1);
    for(i=1;i<=max;i++)
    {
        printf("Enter the edge %d (-1 -1 to exit) : ",i);
        scanf("%d %d",&ori,&des);
        if((ori==-1) && (des==-1))
        {
            break;
        }
        if(ori>=n || des>=n ||ori<0 || des<0)
        {
            printf("This edge is not exist :\n ");
            i--;
        }
        else
        {
            adj[ori][des]=1;
        }
    }
}
