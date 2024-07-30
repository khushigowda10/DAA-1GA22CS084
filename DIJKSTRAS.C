#include <stdio.h>
#include <stdlib.h>
void dij(int cost[10][10],int n,int source)
{
    int i,u,v,count=1,dist[10],visited[10],min;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        dist[i]=cost[source][i];
    }
    visited[source]=1;
    dist[source]=0;
    while(count<=n)
    {
        min=999;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==0 && dist[i]<min)
            {
                min=dist[i];
                u=i;
            }
        }
        visited[u]=1;
        count++;
        for(i=1;i<=n;i++)
        {
            if(dist[i]>dist[u]+cost[u][i])
                dist[i]=dist[u]+cost[u][i];
        }
    }
    printf("\nShortest path from %d\n",source);
    for(i=1;i<=n;i++)
        printf("\n%d to %d is %d",source,i,dist[i]);
}

int main()
{
    int n,cost[10][10],i,j,source;
    printf("\nRead number of nodes:");
    scanf("%d",&n);
    printf("\nRead source vertex:");
    scanf("%d",&source);
    printf("\nRead cost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    dij(cost,n,source);
    return 0;
}
