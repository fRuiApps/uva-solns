#include<iostream>
using namespace std;
int n;
string graph[26];
bool seen[26][26];
void flood(int r,int c)
{
    if((r<0) || (c<0) || (c>n) || (r>n)) return;
	if((seen[r][c] == true) || graph[r][c] != '1') return;
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
    while(cin>>n)
    {
          for(i=0;i<26;i++)
          {
              graph[i].clear();
              for(j=0;j<26;j++)
              seen[i][j] = false;
          }
          
          ans = 0;       
          for(i=0;i<n;i++)
          cin>>graph[i]; 
          for(i=0;i<n;i++)
          for(j =0;j<n;j++)
          {
                if(graph[i][j] == '1' && seen[i][j] == 0)
                {
                               flood(i,j);
                               ans++;  
                }
          }
          cout<<"Image number "<<count++<<" contains "<<ans<<" war eagles.\n";
          
    }
    return 0;
}
