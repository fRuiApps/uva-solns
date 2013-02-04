#include<iostream>
using namespace std;
long long fn(long long n);
int main()
{
    long long  p,q,sum; 
    while((cin>>p>>q) && (p > -1 && q > -1))
    {
        
       if(p)
       {sum = fn(q)-fn(p-1);cout<<"sending "<<q<<"  "<<p-1<<endl;}
       else
       {sum = fn(q) ;cout<<"sending "<<q<<endl;}
       cout<<sum<<endl;
    }
    return 0;
} 





long long fn(long long n)
{
        
        cout<<"received "<<n<<endl;
        long long m,s1 = 0,s2 = 0;
        while(n)
        {
                m = n%10;
                n = n/10;
                s1 += ( ( m * (m+1) ) / 2 );
                s2 +=  n * 45;
                cout<<m<<"  "<<n<<"  "<<s1<<"  "<<s2<<endl;
        }
        return (s1 + s2);
} 
