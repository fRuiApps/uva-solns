#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    long double n,p,k,l;
    while(cin>>n>>p){
                     k = exp((log(p))/n);
                     if((k - int(k))>0.5)
                     k = int(k)+1;
                     else
                     k = int(k);
                     cout<<k<<endl;
    }
    return 0;
}
