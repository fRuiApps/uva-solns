#include<iostream>
using namespace std;
int LIS(int *A,int *T,int l)
{
    int L[l],m=1,i,j;
    L[1]=1;
    for(i=2;i<l;i++)
    {
     L[i]=1;
     for(j=1;j<i;j++) if((A[T[i]]>A[T[j]]) && (L[i]<(L[j]+1))) L[i]=L[j]+1;
     if(m<L[i]) m=L[i];
    }
    return m;
} 
int main()
{
    int N,A[21],T[21],i,j;
    bool end=false;
    cin>>N;
    for(i=1;i<=N;i++) cin>>A[i];
    while(true)
    {
     for(i=1;i<=N;i++)
     if(cin>>j) T[j]=i; else {end=true; break;}
     if(end) break;
     cout<<LIS(A,T,(N+1))<<endl;
    }
    return 0;
}
