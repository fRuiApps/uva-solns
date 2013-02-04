#include<iostream>
#include<queue>
#define inf 1<<16;
bool G[30][30];
void bfs(int);
int maxi,parent[30],cost[30];
using namespace std;
int main()
{
    string str1,str2;
    int n,i,j,cond,ntc,a,b,go,ans[30],cnt;
    cin>>n;
    while(n--)
    {
          for(i=0;i<30;i++) for(j=0;j<30;j++) G[i][j] = 0;
          cin>>cond>>ntc;
          for(i=0;i<cond;i++)
          {
                cin>>str1>>str2;
                a =  (int)(str1[0]-'A')+1;b = (int)(str2[0] - 'A')+1;
                G[a][b] = G[b][a] = 1;
                if(maxi<a) maxi = a; if(maxi<b) maxi = b;
          }
          for(j=0;j<ntc;j++)
          {
                   cnt = 0;
                   cin>>str1>>str2;
                   for(i=0;i<30;i++) {parent[i] = -1;cost[i] = inf;ans[i] = 0;}
                   bfs(str1[0]-'A'+1);
                   go = str2[0]-'A'+1;
                   while(go != -1 && go != str1[0]-'A'+1)
                   {
                      ans[cnt++] = go;        
                      go = parent[go];
                   }
                   cout<<str1[0];
                   for(i=cnt-1;i>=0;i--)
                   cout<<(char)(ans[i]+'A'-1);
                   cout<<endl;
          }
          if(n != 0) cout<<endl;
    }     
    return 0;
}
void bfs(int node)
{
     queue<int>q;
     q.push(node);
     int start,i;
     cost[node]  = 0;
     while(!q.empty())   
     {
          start = q.front();
          q.pop();
          for(i=1;i<=maxi;i++)
          {
               if(cost[i]>cost[start]+1 && G[start][i] == 1)
               {
                  cost[i] = cost[start]+1;
                  parent[i] = start;
                  q.push(i);
               }
          }
     }
}
                
