#include<iostream>
#define INF 1<<30
using namespace std;
int max_ht(int dim1,int dim2,int A[][3],int n)
{
    int i,m=0,h1,h2,h3,m1,x,y,z;
    //cout<<dim1<<" "<<dim2<<endl;
    for(i=0;i<n;i++)
    {
     m1=0;x=A[i][0];y=A[i][1];z=A[i][2];
     if((x>=dim1 || y>=dim2)&&(y>=dim1 || x>=dim2)) h1=0; else {
                 cout<<dim1<<" "<<dim2<<" "<<i<<" "<<x<<" "<<y<<endl;
                 h1=z+max_ht(x,y,A,n);}
     if((y>=dim1 || z>=dim2)&&(y>=dim1 || z>=dim2)) h2=0; else {
                 cout<<dim1<<" "<<dim2<<" "<<i<<" "<<y<<" "<<z<<endl;
                 h2=x+max_ht(y,z,A,n);}
     if((x>=dim1 || z>=dim2)&&(x>=dim1 || z>=dim2)) h3=0; else {
                 cout<<dim1<<" "<<dim2<<" "<<i<<" "<<x<<" "<<z<<endl;
                 h3=y+max_ht(x,z,A,n);}
     if(h1>m1) {m1=h1;}
     if(h2>m1) {m1=h2;}
     if(h3>m1) {m1=h3;}
     if(m<m1) {m=m1;}
    }
    return m;
}
int main()
{
    int N,i,j=0,A[40][3];
    while(true) {
                 cin>>N;
                 if(N==0) break;
                 for(i=0;i<N;i++) cin>>A[i][0]>>A[i][1]>>A[i][2];++j;
                 cout<<"Case "<<j<<": maximum height = "<<max_ht(INF,INF,A,N)<<endl;
                }
    return 0;
}
