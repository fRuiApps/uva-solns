#include<iostream>
#include<iomanip>
#define CASES 1000
#define MAXOBJ 1000
using namespace std;
int MC[31][1005];
int max_carry(int limit,int st,int end,int * P,int * W)
{
    int a,b;
    if(st==end) if(W[st]<=limit) return P[st]; else return 0;
    if(MC[limit][st]) return MC[limit][st];
    b=max_carry(limit,st+1,end,P,W);
    a=(W[st]>limit)?0:(P[st]+max_carry(limit-W[st],st+1,end,P,W));
    MC[limit][st]=(a>b)?a:b;
    return MC[limit][st];
}
int main()
{
    int P[MAXOBJ],W[MAXOBJ],T,N,MW,i,j,k,s,G;
    cin>>T;
    for(i=1;i<=T;i++)
    {
     for(j=0;j<31;j++) for(k=0;k<1005;k++) MC[j][k]=0;
     s=0;for(j=0;j<31;j++) MC[j][k]=0;
     cin>>N;
     for(j=0;j<N;j++) cin>>P[j]>>W[j];
     cin>>G;
     for(j=1;j<=G;j++) {
                        cin>>MW;
                        s+=max_carry(MW,0,N-1,P,W);
     }
     cout<<s<<endl;
    }
    return 0;
}
