#include<iostream>
#include<queue>
using namespace std;
int dist[103],maxi;
bool G[103][103];
void bfs(int node);
int main()
{   
    int j,i,r,c,p,q,source,pos,ans,kase = 1; 
    while(cin>>maxi && maxi)
    {
         for(i=0;i<maxi;i++) {dist[i] = 0;for(j = 0;j<maxi;j++)  G[i][j] = 0;}
         cin>>source;
         while(cin>>p>>q && (p||q))
         G[p-1][q-1]  = 1;  
         bfs(source-1);
         ans = 0;
         for(i=0;i<maxi;i++)
         if(dist[i]>ans) {pos = i+1;ans = dist[i];}
         cout<<"Case "<<kase++<<": The longest path from "<<source<<" has length "<<ans<<", finishing at "<<pos<<".\n\n";
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
        for(i=0;i<maxi;i++)
        {
            if(G[start][i] == 1 && dist[i]<dist[start] + 1 )
            {
               q.push(i);
               dist[i] =   dist[start]+1;
            }
        } 
     }
}
        
