#include<stdio.h>
#define MAX 100
int adj[MAX][MAX];
int main()
{
    int max,i,j,ori,des,n;
    int graph;
    printf("Enter 1 for the undirected graph or Enter 2 for the directed graph : ");
    scanf("%d",&graph);
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    if(graph==1)
    {
        max=n*(n-1)/2;
    }
    else
    {
        max=n*(n-1);
    }
    for(i=1;i<=max;i++)
    {
        printf("Enter edge %d (-1 -1 to quit.) ",i);
        scanf("%d %d",&ori,&des);
        if(ori==-1&&des==-1)
        {
            break;
        }
        if(ori>n||des>n||ori<=0||des<=0)
        {
            printf("invalid vertex.\n");
            i--;
        }
        else
        {
            adj[ori][des]=1;
                if(graph==1)//if undirected graph
                {
                    adj[des][ori]==1;
                }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%4d",adj[i][j]);
        }
        printf("\n");
    }
}
