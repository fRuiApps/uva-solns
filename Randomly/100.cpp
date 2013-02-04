#include<iostream>
using namespace std;
long long ans[999999];
int main()
{
    long long i,cal,n1,n2,max;
    ans[1] = 0;
    for(i = 2;i<=999999;i++)
    {
          cal = i;
          while(cal != 1)
          {
                    ++ans[i]; 
                    if(cal%2==0)cal /= 2;
                    else cal = 3*cal+1;
          }
    }
    while(cin>>n1>>n2)
    {
                    cout<<n1<<" "<<n2;
                    if(n1>n2) swap(n1,n2);
                    max =0;
                    for(i =n1;i<=n2;i++)
                    if(ans[i]>max) max = ans[i];
                    cout<<" "<<max+1<<endl;
    }
    return 0;
}
                    
                  
          
    
