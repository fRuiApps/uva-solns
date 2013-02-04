#include<iostream>
#include<queue>
#include<map>
#define INF 1<<16
using namespace std;
void bfs(int);
bool G[33][33] = {0}; 
int dist[33],maxi;
int main()
{
    int n,ttl,i,j,kase =  1,cnt;
    string p,q,node;
    map<string,int> m;
    while(cin>>n && n)
    {
         m.clear();
         for(i=0;i<33;i++) {for(j=0;j<33;j++) G[i][j] = 0;}
         cnt = 1;
         for(i=0;i<n;i++)
         {
             cin>>p>>q;
             if(m[p] == 0) m[p] = cnt++;
             if(m[q] == 0) m[q] = cnt++;
             G[m[p]][m[q]]    = G[m[q]][m[p]] = 1;
         }
         maxi = cnt;
         while(cin>>node>>ttl && (node != "0" || ttl != 0))
         {
            for(i=0;i<=maxi;i++) dist[i] = INF;
            bfs(m[node]);
            cnt = 0;
            for(i = 1;i<maxi;i++)
            if(dist[i] > ttl) cnt++;
            cout<<"Case "<<kase++<<": "<<cnt<<" nodes not reachable from node "<<node<<" with TTL = "<<ttl<<"."<< endl;
         }
      }
      return 0;
}

void bfs(int node)
{
     int i,start;
     queue<int> q;q.push(node);
     dist[node]=0;
     while(!q.empty())
     {
          start = q.front();q.pop();
          for(i=1;i<maxi;i++)
          {
                if(G[start][i] == 1 && dist[i]>dist[start]+1)
                {
                   dist[i] = dist[start]+1;
                   q.push(i);
                }
          }
     }
}
