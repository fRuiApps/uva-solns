#include <iostream>
using namespace std;
int main() 
{
    long long i,j,n,v,c; 
    long long coin[5] = { 50,25,10,5,1 };
    while(cin>>n) 
    {
         v = 5;
         long long nway[100000] = {0};
         nway[0] = 1;
         for (i=0;i<v;i++)
         {
              c = coin[i];
              for (j=c; j<=n; j++)
              nway[j] += nway[j-c];
         }
         if(nway[n] == 1)
         cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
         else
         cout<<"There are "<<nway[n]<<" ways to produce "<<n<<" cents change."<<endl;
    }
    return 0;
}


