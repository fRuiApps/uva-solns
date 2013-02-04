#include<iostream>
#include<queue>
using namespace std;
void bfs(int);
bool G[30][30],seen[30][30]; 
int maxi;
int main()
{
    int ntc,i,j,ans,one = 0;
    char c,d ;
    cin>>ntc;
    while(ntc--)
    {
           for(i=0;i<30;i++) for(j=0;j<30;j++)G[i][j] = seen[i][j] = 0;ans = 0;
           cin>>c;getchar();maxi = c - 'A';   
           while((c = getchar())&& c != '\n' && c != EOF) 
           {
                     
                    d = getchar();
                    G[c - 'A'][c - 'A'] =   G[c - 'A'][d - 'A'] = G[d - 'A'][d - 'A'] =  G[d - 'A'][c - 'A'] = 1;
                    if(getchar() ==  EOF) break;
           }
           maxi +=1;
           for(i=0;i<maxi;i++)
           {
              for(j=0;j<maxi;j++) //cout<<G[i][j];cout<<endl;
              if(G[i][j] == 1 && seen[i][j] == 0){bfs(i);ans++;}
           }
           for(i=0;i<maxi;i++)
           if(G[i][i] == 0) ans++;
           
           if(one == 0) one = 1; else cout<<endl;
           cout<<ans<<endl;
    }
    return 0;
}
void bfs(int r)
{
     queue<int> q;
     int i,top,l,k;
     q.push(r);
     while(!q.empty())
     {
              top = q.front();
              q.pop();
              for(i=0;i<maxi;i++)
              {
                      if(G[top][i] == 1 && seen[top][i] == 0) 
                      {seen[top][i] = 1;q.push(i);}
              }
     }
}  
     
            
            
       
