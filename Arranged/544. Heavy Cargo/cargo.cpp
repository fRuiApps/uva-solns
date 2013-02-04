#include<iostream>
#include<string>
#define INF 100000
using namespace std;
int main()
{
    int i,j,n,r,k,d,t,n1,n2,c=0,A[230][230];
    string places[230],a1,a2;
    while(true) {
                 cin>>n>>r;if(n==0) break;t=0;
                 for(i=0;i<n;i++) for(j=0;j<n;j++) A[i][j]=-1;
                 for(i=0;i<r;i++) {
                                   cin>>a1>>a2>>d;
                                   for(j=0;j<t;j++) if(places[j]==a1) {n1=j;break;}
                                   if(j==t) {places[t++]=a1;n1=t-1;}
                                   for(j=0;j<t;j++) if(places[j]==a2) {n2=j;break;}
                                   if(j==t) {places[t++]=a2;n2=t-1;}
                                   A[n1][n2]=A[n2][n1]=d;
                 }
                 cin>>a1>>a2;++c;
                 for(j=0;j<t;j++) if(places[j]==a1) {n1=j;break;}
                 if(j==t) {places[t++]=a1;n1=t-1;}
                 for(j=0;j<t;j++) if(places[j]==a2) {n2=j;break;}
                 if(j==t) {places[t++]=a2;n2=t-1;}
                 for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++) {
                                                                     t=(A[i][k]<A[k][j])?A[i][k]:A[k][j];
                                                                     A[i][j]=(A[i][j]<t)?t:A[i][j];
                 }
                 cout<<"Scenario #"<<c<<endl<<A[n1][n2]<<" tons\n\n";
    } 
    return 0;
} 
