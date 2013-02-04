#include<iostream>
#define MAX 10010
using namespace std;
int L[MAX],rL[MAX];
int LIS(int * A,int l)
{
    int i,j;
    L[0]=1;
    for(i=1;i<=l;i++)
    {
     L[i]=1;
     for(j=0;j<i;j++) if((A[i]>A[j]) && (L[i]<(L[j]+1))) L[i]=L[j]+1;
    }
    return L[l];
}
int revLIS(int * A,int l,int end)
{
    int i,j;
    rL[end]=1;
    for(i=end-1;i>=l;i--)
    {
     rL[i]=1;
     for(j=end;j>i;j--) if((A[i]>A[j]) && (rL[i]<(rL[j]+1))) rL[i]=rL[j]+1;
    }
    return rL[l];
}
int main()
{
    int i,j,m,A[MAX],N;
    while(cin>>N) {
                   for(i=0;i<N;i++) cin>>A[i];m=0;LIS(A,N-1);revLIS(A,0,N-1);
                   for(i=0;i<N;i++) {if(L[i]==rL[i]) {j=L[i]+rL[i]-1;if(m<j) m=j;}}
                   cout<<m<<endl;
                  }
    return 0;
}
