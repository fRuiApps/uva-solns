#include<iostream>
using namespace std;
bool isPoss(int i,int t,int &m,int &n)
{
     if(i==m) return true;
     else if(i<=0 || i>n) return false;
     else return (isPoss(i+t,t+2,m,n) || isPoss(i-t,t+2,m,n));
}
int main()
{
    int N,M;
    while(true)
    {
     cin>>N>>M;
     if(N==0) break;
     if(N>=49) cout<<"Let me try!\n";
     else {
     if(isPoss(1,3,M,N)) cout<<"Let me try!\n";
     else cout<<"Don't make fun of me!\n";
     }
    }
    return 0;
}
