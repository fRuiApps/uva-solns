#include<iostream>
using namespace std;
long long rev(long long);
int main()
{
    long long i,j,n,r;
    bool sieve[1000000] = {0};
    for(i =2;i<1000;i++)
    {
          for(j=i*i;j<=1000000;j+=i)
          sieve[j]=1;
    }
    while(cin>>n)
    {
                 if(sieve[n]==0)
                 {
                                r = rev(n);
                                if(sieve[r]==0 && r != n)
                                cout<<n<<" is emirp.\n";
                                else
                                cout<<n<<" is prime.\n";
                 }
                 else
                 cout<<n<<" is not prime.\n";
    }
    return 0;
}
long long rev(long long n)
{
     long long n1 = 0;
     while(n!=0)
     {
                n1 = (n1*10) + n%10;
                n /= 10;
     }
     return n1;
}
                
