#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define visited 2
#define NIL -1
int n;
int adj[MAX][MAX];
int predecessor[MAX];
int state[MAX];
int top=-1;
int stack[MAX];
void dfs(int v);
void ds_traversal();
void create_graph();
void push(int v);
int pop();
int isempty();
main()
{
    create_graph();
    ds_traversal();
}
void ds_traversal()
{
    int v;
    for(v=0;v<n;v++)
    {
        state[v]=initial;
        predecessor[v]=NIL;
    }
    printf("Enter the starting vertex for DFS : ");
    scanf("%d",&v);
    dfs(v);
    for(v=0;v<n;v++)
    {
        if(state[v]==initial)
            dfs(v);
    }
    printf("\n");
    for(v=0;v<n;v++)
    {
        printf("Vertex is %d, Predecessor is %d", v, predecessor[v]);
        printf("\n");
    }
    printf("Tree Edges : ");
    for(v=0;v<n;v++)
    {
        if(predecessor[v]!=-1)
            printf("Tree edges %d->%d\n",predecessor[v], v);
    }
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
            printf("%d",v);
            state[v]=visited;
        }
        for(i=n-1;i>=0;i--)
        {
            if(adj[v][i]==1 && state[i]==initial)
            {
                push(i);
                predecessor[i]=v;
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
    else
    {
        top=top+1;
        stack[top]=v;
    }
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
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void create_graph()
{
    int max,i,ori,des;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    max=n*(n-1);
    for(i=1;i<=max;i++)
    {
        printf("Enter the edge %d (-1 -1 to exit) : ",i);
        scanf("%d %d",&ori,&des);
        if(ori==-1 && des==-1)
        {
            break;
        }
        if(ori>=n || des>=n || ori<0 || des<0)
        {
            printf("This edge does not exit.\n");
            i--;
        }
        else
        {
            adj[ori][des]=1;
        }
    }
}
