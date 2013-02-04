#include<iostream>
using namespace std;
int main()
{
    int n,d,temp,first;
    while(cin>>n>>d)
    {
                    first = 0;
                    cout<<"[";
                    if(n == 1)
                    cout<<"0;2";
                    while(n != 1)
                    {
                              cout<<(n/d);
                              if(first == 0) {cout<<";";first = 1;}
                              else
                              if(d != 1) cout<<",";
                              temp = n%d;
                              n = d;
                              d = temp;
                    }
                    cout<<"]"<<endl;
    }
    return 0;
}
