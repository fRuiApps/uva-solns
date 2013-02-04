#include<iostream>
long long bigmod(long long,long long,long long);
using namespace std;
int main()
{
    bool sieve[65025] = {0},ans; 
    long long i,j,n;
    for(i = 2;i<=255;i++)
    {
          for(j = i*i;j<=65025;j+=i)
          sieve[j] = 1;
    }
    while(cin>>n && n != 0)
    {
       ans = false;          
       if(sieve[n] == 1)
       {
             ans = true;
            for(i = 2;i<n;i++)
            if(bigmod(i,n,n) != i) { ans = false; break;}
       }
       if(ans == true)
       cout<<"The number "<<n<<" is a Carmichael number.\n";
        else
       cout<<n<<" is normal.\n";
    }
    return 0;
}
long long bigmod(long long base,long long index,long long remnum)
{
    long long res,ret;
     if(index == 0) {ret = 1;
     return ret;}
     
     else if((index%2) == 0)
     {
          res = bigmod( base, (index/2), remnum);
          ret =  (res*res) %remnum;
          return ret;
     }
     
     else
     {
         ret =  ((base%remnum)*bigmod( base , index - 1,remnum))%remnum;
         return ret;
     }
}
          
          
