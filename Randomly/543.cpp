#include<iostream>
using namespace std;
int main()
{
    bool sieve[1000000] = {0},printed;
    sieve[0] = 0;sieve[1] = 0;
    long int i,j,n;
    for(i = 2;i<=1000;i++)
    {
          for(j = i*i;j<=1000000;j+=i)
          sieve[j] = 1;
    }
    
    while(cin>>n&&n!=0)
    {
            printed = 0;i = 2;
            while(printed==0)
            {
                  if(sieve[i]==0&&sieve[n-i] == 0)             
                  {
                        if(i == n) cout<<"NO WAY\n";
			else cout<<n<<":\n"<<sieve[i]<<"+"<<sieve[n-i]<<"\n";
                       printed = 1;
                  }
                  i++;                      
            }
    }
    return 0;
}
                       
