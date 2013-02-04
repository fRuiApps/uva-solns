#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    unsigned int n,x;
    while(cin>>n && n != 0)
    {
                 x = sqrt(n);
                 if(x*x == n)
                 cout<<"yes"<<endl;
                 else
                 cout<<"no"<<endl;
    }
    return 0;
}
