#include<iostream>
using namespace std;
int R,C;
string graph[101];
bool seen[101][101];
void flood(int r,int c)
{
    if((r<0) || (c<0) || (c>C) || (r>R)) return;
	 if((seen[r][c] == true) || graph[r][c] != '@') return;
	 seen[r][c] = true;
     for(int i = -1; i<= 1; i ++) 
     {
       for(int j = -1; j <= 1; j ++)
       if( i!= 0 || j!= 0) 
       flood(r+i,c+j);
     }
}
int main()
{
    int ans,i,j,count = 1;
    while(cin>>R>>C && R != 0 && C != 0)
    {
          for(i=0;i<101;i++)
          {
              graph[i].clear();
              for(j=0;j<101;j++)
              seen[i][j] = false;
          }
          ans = 0;       
          for(i=0;i<R;i++)
          cin>>graph[i]; 
          for(i=0;i<R;i++)
          for(j =0;j<C;j++)
          {
             if(graph[i][j] == '@' && seen[i][j] == 0)
             {
                   flood(i,j);
                   ans++;  
             }
          }
          cout<<ans<<endl;
    }
    return 0;
}
