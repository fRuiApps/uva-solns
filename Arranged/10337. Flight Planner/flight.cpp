#include<iostream>
#define MAX 1001
#define INF 1<<29
using namespace std;
int MIN(int a,int b,int c)
{
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}
int main()
{
    int i,j,k,X,N,A[10][MAX],m,minfuel[10][MAX];
    cin>>N;
    for(i=1;i<=N;i++) {
                       cin>>X;
                       m=X/100;
                       for(j=9;j>=0;j--) for(k=0;k<m;k++) cin>>A[j][k];
                       for(j=9;j>=0;j--) for(k=0;k<m;k++) minfuel[j][k]=INF;minfuel[0][0]=0;
                       for(k=1;k<m;k++) {
                                         minfuel[0][k]=MIN(minfuel[1][k-1]+20-A[1][k-1],minfuel[0][k-1]+30-A[0][k-1],INF);
                                         minfuel[9][k]=MIN(minfuel[9][k-1]+30-A[9][k-1],minfuel[8][k-1]+20-A[8][k-1],INF);
                                         for(j=1;j<=8;j++) {
                                                            minfuel[j][k]=MIN(minfuel[j][k-1]+30-A[j][k-1],minfuel[j-1][k-1]+60-A[j-1][k-1],minfuel[j+1][k-1]+20-A[j+1][k-1]);
                                                            if(minfuel[j][k]>=INF) minfuel[j][k]=INF;
                                                           }
                                        }
                       cout<<MIN(minfuel[0][m-1]+30-A[0][m-1],minfuel[1][m-1]+20-A[1][m-1],INF)<<endl<<endl;
                       
    }                                                                        
    return 0;
}
