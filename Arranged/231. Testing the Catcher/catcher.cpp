#include<iostream>
using namespace std;
int LDS(int *A,int l)
{
    int L[l],m=1,i,j;
    L[0]=1;
    for(i=1;i<l;i++)
    {
     L[i]=1;
     for(j=0;j<i;j++) if((A[i]<A[j]) && (L[i]<(L[j]+1))) L[i]=L[j]+1;
     if(m<L[i]) m=L[i];
    }
    return m;
} 
int main()
{
    int c=1,A[1000],i=0,j;
    bool f=false;
    while(true)
    {
     cin>>A[i];
     if(A[i]==-1 && i==0) break;
     if(A[i]==-1) {
                   if(f) cout<<endl; else f=true;
                   cout<<"Test #"<<c<<":"<<endl;
                   cout<<"  maximum possible interceptions: "<<LDS(A,i)<<endl;
                   i=0;c++;
     }
     else i++;
    }
    return 0;
}
