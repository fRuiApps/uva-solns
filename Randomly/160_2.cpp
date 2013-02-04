//printing space on its own
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long n,j,expo,ans,ans_arr[101][25] = {0},i,cnt;
    long prime[ ] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    for(i =2;i<=100;i++)
    {
          for(j=0;j<25;j++ && j <= i)
          {
                           ans = 0;
                           expo= prime[j];
                           while(expo<=i)
                           {
                               ans += (int)floor(i/expo);
                               expo *= prime[j];
                           }
                           ans_arr[i][j] = ans;
          }
          
    }
     
    while(scanf("%d",&n) && n!= 0)
    {
                 cnt = 0;       
                printf("%3d! =",n);
                for(i =0;i<25 && ans_arr[n][i] != 0;i++)
                {
                      if(cnt==15) printf("\n      ");
                      printf("%3d",ans_arr[n][i]);
                      cnt++;
                }
                printf("\n");
    }
    return 0;
}
