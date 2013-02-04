#include<iostream>
using namespace std;
int cycle_length(int n)
{
     if(n==1) return 1;
     if(n&1) return (cycle_length(3*n+1)+1); else return (cycle_length(n/2)+1);
}
int main()
{
    int i,M,j,k,t;
    while(cin>>i>>j)
    {
     M=0;
     if(i<=j) {for(k=i;k<=j;k++) {t=cycle_length(k);if(t>M) M=t;}}
     else {for(k=j;k<=i;k++) {t=cycle_length(k);if(t>M) M=t;}}
     cout<<i<<" "<<j<<" "<<M<<endl;
    }
    return 0;
}
