#include<stdio.h>
#define MAX 100
#define TEMP 0
#define PER 1
#define infinity 9999
#define NIL -1
int n;
int adj[MAX][MAX];
int predecessor[MAX];
int pathlength[MAX];
int status[MAX];
void dijkshtra(int s);
int min_temp();
void findpath(int s,int v);
void create_graph();
main()
{
    int s,v;
    create_graph();
    printf("Enter the source vertex : ");
    scanf("%d",&s);
    dijkshtra(s);
    while(1)
    {
        printf("Enter the destination vertex (-1 to quit) : ");
        scanf("%d",&v);
        if(v==-1)
            break;
        if(v>=n||v<0)
        {
            printf("Not exist.\n");
        }
        else if(v==s)
        {
            printf("Destination and source is equal.\n");
        }
        else if(pathlength[v]==infinity)
        {
            printf("No path exist.\n");
        }
        else
            findpath(s,v);
    }
}
void dijkshtra(int s)
{
    int i,current;
    for(i=0;i<n;i++)
    {
        predecessor[i]=NIL;
        pathlength[i]=infinity;
        status[i]=TEMP;
    }
    pathlength[s]=0;
    while(1)
    {
        current=min_temp();
        if(current==NIL)
            return;
        status[current]=PER;
        for(i=0;i<n;i++)
        {
            if(adj[current][i]!=0 && status[i]==TEMP)
            {
                if(pathlength[current]+adj[current][i]<pathlength[i])
                {
                    predecessor[i]=current;
                    pathlength[i]=pathlength[current]+adj[current][i];
                }
            }
        }
    }
}
int min_temp()
{
    int i;
    int k=NIL;
    int min=infinity;
    for(i=0;i<n;i++)
    {
        if(status[i]==TEMP && pathlength[i]<min)
        {
            min=pathlength[i];
            k=i;
        }
    }
    return k;
}
void findpath(int s,int v)
{
    int count=0;
    int shortlist=0;
    int path[MAX];
    int i,u;
    while(v!=s)
    {
        count++;
        path[count]=v;
        u=predecessor[v];
        shortlist+=adj[u][v];
        v=u;
    }
    count++;
    path[count]=s;
    printf("Shortest path is : ");
    for(i=count;i>=1;i--)
    {
        printf("%d ",path[i]);
    }
    printf("\nShortest distance is : %d\n",shortlist);
}
void create_graph()
{
    int max,i,ori,des,wt;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    max=n*(n-1);
    for(i=1;i<=max;i++)
    {
        printf("Enter the edge %d(-1 -1 to quit):  ",i);
        scanf("%d %d",&ori,&des);
        if(ori==-1 && des==-1)
        {
            break;
        }
        printf("Enter the weight for the edge : ");
        scanf("%d",&wt);
        if(ori>=n || ori<0 || des>=n || des<0)
        {
            printf("Edge does not exist.\n");
            i--;
        }
        else{
            adj[ori][des]=wt;
        }
    }
}
