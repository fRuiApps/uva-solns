#include<iostream>
using namespace std;
int main()
{
    int i,cnt = 0,temp,j,l,*p,n;
    
    cin>>n;
    while(n--)
    {
              cin>>l;
              p = new int [l];
              for(i = 0;i<l;i++) cin>>p[i];
              for(i = 0;i<l;i++)
              {
                    for(j = 0;j<l;j++)
                    {
                           if(p[j]>p[j+1])
                           {
                                          temp = p[j];
                                          p[j] = p[j+1];
                                          p[j+1] = temp;
                                          cnt++;
                           }
                    }
              }
              cout<<"Optimal train swapping takes "<<cnt<<" swaps."<<endl;
              cnt = 0;
    }
    
    
    
    return 0;
}
          
