#include<iostream>
using namespace std;
int main()
{
    int N,i;
    char* fibo[5000];
    fibo[0]=new char[1045];
    fibo[0][0]='1';
    fibo[0][1]='\0';
    cout<<fibo[0];
    //fibo[0]=0;fibo[1]=1;
    //for(i=2;i<=5000;i++) fibo[i]=fibo[i-1]+fibo[i-2];
    //while(cin>>N) cout<<"The Fibonacci number for "<<N<<" is "<<fibo[N]<<endl;
    return 0;
}
