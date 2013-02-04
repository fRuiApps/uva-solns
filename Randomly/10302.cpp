#include<iostream>
using namespace std;
int main()
{
    long long  n,ans;
    while(cin>>n)
    {
                 if(n%2 == 0)
                 ans = (n/2)*(n+1);
                 else
                 ans = n*((n+1)/2);
                 cout<<ans*ans<<endl;
    }
    return 0;
}
