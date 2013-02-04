#include<iostream>
using namespace std;
long arr[2][1000000] = {0},pos[1000000] = {0};
bool present[1000000] = {0};    
int main()
{
    long cnt = 0,i,n;
    while(cin>>n)
    {
         if(!present[n])
          {
                       arr[0][cnt] =  n;
                       arr[1][cnt] = 1;
                       present[n] = 1;
                       pos[n] = cnt++;
          }
         else        
         arr[1][pos[n]]++;
         n = 0;
    }
    for(i=0;i<cnt;i++)
    cout<<arr[0][i]<<" "<<arr[1][i]<<endl;
    return 0;
}    
        
