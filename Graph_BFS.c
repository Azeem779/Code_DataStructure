#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int adj[MAX][MAX];
int n;
int state[MAX];
int queue[MAX],front=-1,rear=-1;
void create_graph();
void bfs_traversal();
void bfs(int v);
void insert(int vertex);
int delete();
int queue_empty();
int main()
{
    create_graph();
    bfs_traversal();
}
void bfs_traversal()
{
    int v;
    for(v=0;v<n;v++)
        state[v]=initial;
    printf("Enter the starting vertex for  BFS : ");
    scanf("%d",&v);
    bfs(v);
}
void bfs(int v)
{
    int i;
    insert(v);
    state[v]=waiting;
        while(!queue_empty())
        {
            v=delete();
            printf("%d ",v);
            state[v]=visited;
                for(i=0;i<n;i++)
                {
                    if(adj[v][i]==1&&state[i]==initial)
                    {
                        insert(i);
                        state[i]=waiting;
                    }
                }
        }
}
void insert(int vertex)
{
    if(rear==MAX-1)
    {
        printf("Overflow\n");
    }
    else
    {
        if(front==-1)
            front=0;
        rear=rear+1;
        queue[rear]=vertex;
    }
}
int queue_empty()
{
    if(front==-1||front>rear)
        return 1;
    else
        return 0;
}
int delete()
{
    int delete;
    if(front==-1||front>rear)
    {
        printf("Underflow.\n");
        exit(1) ;
    }
    delete=queue[front];
    front=front+1;
    return delete;
}
void create_graph()
{
    int max,i,ori,des;
    printf("Enter the number of vertex : ");
    scanf("%d",&n);
    max=n*(n-1);
    for(i=1;i<=max;i++)
    {
        printf("Enter edge %d (-1 -1 to quit.) : ",i);
        scanf("%d %d",&ori,&des);
        if(ori==-1 && des==-1)
            break;
        if(ori>=n||ori<0||des>=n||des<0)
        {
            printf("Edge does not exist.\n");
            i--;
        }
        else
            adj[ori][des]=1;
    }
}
