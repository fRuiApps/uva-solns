#include<iostream>
using namespace std;
int main()
{
    int i = 0,flag = 0,n;
    string str;
    cin>>str;
    if(next_permutation(str.begin(),str.end()))
    cout<<str<<endl;
    else
    cout<<"no solution "<<endl;
    return 0;
}
