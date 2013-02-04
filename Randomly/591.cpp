#include<iostream>
using namespace std;
int main()
{
    long int i, n,height[60],moves ,sumht,avg,cnt = 1;
    
 
    while((cin>>n) && (n != 0))
    {
                 moves =sumht = avg = 0;
                 for(i = 0;i<n;i++)
                 {
                       cin>>height[i];
                       sumht  += height[i];
                       
                 }
                 
                 avg = sumht/n;
                 
                 for(i = 0;i<n;i++)
                 {
                       if(height[i]>avg)
                       moves += (height[i] -avg);
                 }
                 cout<<"Set #"<<cnt++<<endl;
                 cout<<"The minimum number of moves is "<<moves<<"."<<endl<<endl;

    }
    return 0;
}
 
    
