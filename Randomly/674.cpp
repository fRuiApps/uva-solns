
#include <cstdio>
#include<iostream>
using namespace std;
#define MAXTOTAL 100000000
unsigned long long nway[MAXTOTAL+1],ans[MAXTOTAL+1];
long long  coin[5] = { 50,25,10,5,1 };
int main() 
{
    long long i,j,n,v,c,cnt = 0;
    for(n = 0;n<=7489;n++)
    {
                       v = 5;
                       nway[0] = 1;
                       for (i=0; i<v; i++)
                        {
                           c = coin[i];
                           for (j=c; j<=n; j++)
                           nway[j] += nway[j-c];
                        }
                           ans[cnt++] = nway[n];
                           for(i = 0;i<=j;i++) nway[i] = 0;
}
while(cin>>n)
cout<<ans[n]<<endl;

return 0;
}
