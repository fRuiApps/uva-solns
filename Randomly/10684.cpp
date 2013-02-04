#include<iostream>
using namespace std;
#define not_zero() long long n; while(cin>>n && n != 0)
int main()
{
    long long i,j,arr[10005];
    not_zero()
    {
            long long s[10005] = {0},ans = -9999;
            for(i = 1;i<=n;i++)
            cin>>arr[i];
            s[0] = 0;
            for(i=1;i<=n;i++)
            {s[i] = max(s[i-1]+arr[i],arr[i]); if(s[i]>ans) ans = s[i];}
            if(ans>0)
            cout<<"The maximum winning streak is "<<ans<<"."<<endl;
            else 
            cout<<"Losing streak."<<endl;
    }
return 0;
}
