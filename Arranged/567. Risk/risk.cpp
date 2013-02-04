#include<iostream>
#include<iomanip>
#define INF 1000
#define MAX 25
using namespace std;
int main()
{
    unsigned int i,j,k,l,m=1,t,c=0,N,a,b,A[MAX][MAX];
    for(i=1;i<MAX;i++) for(j=1;j<MAX;j++) A[i][j]=(i==j)?0:INF;
    while(cin>>l) {
         for(i=1;i<=l;i++) {cin>>t;A[m][t]=A[t][m]=1;}
         for(m=2;m<=19;m++) {
                             cin>>l;
                             for(i=1;i<=l;i++) {cin>>t;A[m][t]=A[t][m]=1;}
         }
         m=1;c++;
         for(k=1;k<=20;k++) 
             for(i=1;i<=20;i++) 
                 for(j=1;j<=20;j++) 
                     {
                      t=A[i][k]+A[k][j];
                      if(t<A[i][j]) A[i][j]=t;
                     }
         cout<<"Test Set #"<<c<<endl;
         cin>>N;
         for(i=1;i<=N;i++) {cin>>a>>b;cout<<setw(2)<<a<<" to "<<setw(2)<<b<<":"<<setw(2)<<A[a][b]<<endl;}
         cout<<endl;
         for(i=1;i<MAX;i++) for(j=1;j<MAX;j++) A[i][j]=(i==j)?0:INF;
    }
    return 0;
}
