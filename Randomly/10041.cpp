#include<iostream>
using namespace std;
int main()
{
    int ntc,*p,s,i,n,min;
    cin>>ntc;
    while(ntc--)
    {
                cin>>n;
                min = 0;
                p = new int[n];
                for(i=0;i<n;i++)
                cin>>p[i];
                sort(p,p+n);
                s = 0;
                for(i=0;i<n;i++)
                {
                                 
                                           if(p[n/2] - p[i] >0)
                                           s += (p[n/2] - p[i]);
                                           else 
                                           s -= (p[n/2] - p[i]);
                                 
                    
                }
                
                cout<<s<<endl;
    }
    return 0;
}
                
