#include<iostream>
using namespace std;
int main()
{
    unsigned long long scenario,num,i,arr[55];
    cin>>scenario;
    arr[0] = 0;
    arr[1] = 1;
    for(int j = 2;j<=53;j++)
    arr[j] = arr[j-1] + arr[j-2];
                     
    for(i =1;i<=scenario;i++)
    {     
          cin>>num;
          cout<<"Scenario #"<<i<<":"<<endl<<arr[num+2]<<endl<<endl;
          
    }
    return 0;
}
          
