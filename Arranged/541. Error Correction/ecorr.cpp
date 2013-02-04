#include<iostream>
#define MAX 100
using namespace std;
int main()
{
    int sumR[MAX]={0},sumC[MAX]={0},A[MAX][MAX],n,i,j,R,C;
    while(true)
    {
     cin>>n;
     if(n==0) break;
     for(i=0;i<MAX;i++) sumR[i]=sumC[i]=0;
     for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     {cin>>A[i][j];sumR[i]+=A[i][j];sumC[j]+=A[i][j];}
     R=C=0;
     for(i=0;i<n;i++)
     {if(sumR[i]&1) R++; if(sumC[i]&1) C++;}
      if(R==0 && C==0) cout<<"OK\n";
     else if(R!=1 || C!=1) cout<<"Corrupt\n";
     else {
           for(i=0;i<n;i++) if(sumR[i]&1) {R=i;break;}
           for(i=0;i<n;i++) if(sumC[i]&1) {C=i;break;}
           cout<<"Change bit ("<<R+1<<","<<C+1<<")\n";}
    }
    return 0;
}
