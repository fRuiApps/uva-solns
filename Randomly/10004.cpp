#include<iostream>
#include<queue>
using namespace std;
bool G[200][200],visited[200],flag;
static int maxi,color[200];
void bfs(int);
int main()
{
    int i,j,k,edge,min;
    while(cin>>maxi && maxi)
    {
          maxi += 1;          
          for(i =0;i<maxi;i++) {visited[i] = 0;color[i]  = -1;for(j =0;j<maxi;j++) G[i][j] = 0;}
          flag = 0;min = 1<<10;
          cin>>edge;
          for(k=0;k<edge;k++)
          {cin>>i>>j; G[i][j] = 1;if(i<min) min = i;if(j<min) min = j;}
          bfs(min);
          if(flag == 1) cout<<"NOT BICOLORABLE.\n";
          else cout<<"BICOLORABLE.\n";
         
    }
    return 0;
}
void bfs(int r)
{
     queue<int> q;
     int i,node,l,k;
     q.push(r);
     color[r] = 1;
     while(!q.empty())
     {
              node = q.front();
              q.pop();
              for(i=0;i<maxi;i++)
              {
                     // cout<<node<<" "<<visited[node]<<" "<<G[node][i]<<endl;           
                      if(G[node][i] == 1 && visited[node] == 0) 
                      {
                                    //for(k=0;k<maxi;k++) cout<<color[k]<<" ";   cout<<endl;
                                    if(color[i] == color[node]){flag = 1;break;}
                                    else
                                    if(color[i] == -1) color[i] = color[node]^1;
                                    q.push(i);
                      }
              }
              visited[node] = 1;
     }
}  

