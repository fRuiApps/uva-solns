#include<iostream>
using namespace std;
int main()
{
    long long m,n,i;
    s1:
    while(cin>>n>>m)
    {
          long long arr[50000] = {0},cnt = 0;
          if(m<2||n<2)
          {
             cout<<"Boring!\n";
             goto s1; 
          }
                          
          while(n%m == 0 && n != 1)
          {
                    arr[cnt++] = n;
                    n /= m;
          }
          if(n == 1)
          {
               for(i = 0;i<cnt;i++)
               cout<<arr[i]<<" ";
               cout<<"1"<<endl;
          }
          else
          cout<<"Boring!\n";
    }
    return 0;
}
