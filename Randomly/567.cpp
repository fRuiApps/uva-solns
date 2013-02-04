#include<cstdio>
#include<queue>
using namespace std;
void bfs(int);
bool G[23][23] = {0}; 
int dist[23];
int main()
{
    int n,i,j,p,q,k,temp,kase = 1;
    while(scanf("%d",&n) != EOF)
    {
        for(i=0;i<=20;i++) for(j=0;j<=20;j++) G[i][j] = 0;
        for(j=0;j<n;j++) { scanf("%d",&temp); G[1][temp] = G[temp][1] = 1;}
        for(i=2;i<20;i++)
        {
            scanf("%d",&n);
            for(j=0;j<n;j++) { scanf("%d",&temp); G[i][temp] = G[temp][i] = 1;}
        }
        scanf("%d",&n);
        printf("Test Set #%d\n",kase++);
        for(k=0;k<n;k++)
        {
           scanf("%d%d",&p,&q);
           for(i=0;i<=20;i++) dist[i] = 0;
           bfs(p);
           printf("%2d to %2d: %d\n",p,q,dist[q]);
        }
        printf("\n");
    }
    return 0;
}
void bfs(int node)
{
     int i,start;
     queue<int> q;q.push(node);
     while(!q.empty())
     {
          start = q.front();q.pop();
          for(i=1;i<=20;i++)
          {
                if(G[start][i] == 1 && (dist[i]>dist[start]+1 || dist[i] == 0))
                {
                   dist[i] = dist[start]+1;
                   q.push(i);
                }
          }
     }
}
