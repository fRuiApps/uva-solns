#include<cstdio>
using namespace std;
int main()
{
    long long n;
    while(scanf("%lld",&n)==1)
    {
           if(n<0) break;
           else
           printf("%lld\n",((n*(n+1))/2)+1);
    }
    return 0;
}
    
