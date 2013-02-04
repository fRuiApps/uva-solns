#include<iostream>
using namespace std;
int A[100000000];
int max_r;
int cycle_length(int n)
{
     int t,temp;
     if(max_r<n) max_r=n;
     if(n<100000000) {
     if(A[n]) return A[n];
     if(n&1)
     {
      t=3*n+1;
      A[n]=cycle_length(t)+1;
     }
     else
     {
      t=n/2;
      A[n]=cycle_length(t)+1;
     }
     return A[n];
     }
}
int main()
{
    int i,M,j,k,temp;
    A[1]=1;
    for(i=2;i<=1000000;i++) A[i]=cycle_length(i);
    while(cin>>i>>j)
    {
     M=0;
     if(i<=j) {for(k=i;k<=j;k++) if(A[k]>M) M=A[k];}
     else {for(k=j;k<=i;k++) if(A[k]>M) M=A[k];}
     cout<<i<<" "<<j<<" "<<M<<endl;
    }
    //cout<<max_r<<endl;
    return 0;
}
