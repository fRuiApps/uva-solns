#include<iostream>
#include<iomanip>
#define INF 3<<29;
using namespace std;
int min(int a,int b,int c,int d,int e,int f,int &t)
{
    if(a<=b && a<=c) {t=d;return a;}
    else if(b<=a && b<=c) {t=e;return b;}
    else {t=f;return c;}
} 
int main()
{
    int A[12][102],M[12][102],Ref[12][102],i,j,m,n,a,b,c,temp,st;
    bool f;
    while(cin>>m>>n)
    {
     f=false;
     temp=INF;
     for(i=1;i<=m;i++) for(j=1;j<=n;j++) cin>>A[i][j];
     for(i=0;i<=(n+1);i++) M[0][i]=M[m+1][i]=INF;
     for(i=1;i<=m;i++) M[i][0]=M[i][n+1]=INF;
     for(i=1;i<=m;i++) M[i][n]=A[i][n];
     for(j=(n-1);j>=1;j--) for(i=m;i>=1;i--) {
     if(i==1) {a=i;b=(i+1);c=m;} else if(i==m) {a=1;b=(i-1);c=i;} else {a=i-1;b=i;c=i+1;}
     M[i][j]=min(A[i][j]+M[a][j+1],A[i][j]+M[b][j+1],A[i][j]+M[c][j+1],a,b,c,Ref[i][j]);
     }
     for(i=1;i<=m;i++) if(temp>M[i][1]) {temp=M[i][1];st=i;}
     i=st;
     for(j=1;j<=n;j++) {if(f) cout<<" "; else f=true; cout<<i;i=Ref[i][j];}
     cout<<endl<<temp<<endl;
    }
    return 0;
}
