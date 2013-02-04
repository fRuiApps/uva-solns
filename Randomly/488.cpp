#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k,l,amp,freq;   
    cin>>n;k = n;
    while(n--)
    {
       cin>>amp>>freq;
       //if(n != k-1) cout<<endl;
       if(amp>40) amp = 40;
        
       while(freq--)
       {
                    for(i=1;i<=amp;i++)
                    {
                        for(j=1;j<=i;j++)
                        cout<<i;
                        cout<<"\n";
                    }
                    for(i=amp-1;i>0;i--)
                    {
                          for(j=1;j<=i;j++)
                          cout<<i;
                          cout<<"\n";
                    }
                    if(!(n == 0 && freq == 0))
                    cout<<"\n";
       }
        
    }
}
 
