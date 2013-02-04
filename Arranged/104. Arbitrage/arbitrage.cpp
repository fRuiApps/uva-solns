#include<iostream>
#define MAX 25
using namespace std;
void print_path(int P[][MAX][MAX],int i,int j,int k)
{
    if(k==0) 
             cout<<i;
    else {
          print_path(P,i,P[i][j][k],k-1);
          cout<<" "<<j;
    }       
}
int main()
{
    int i,j,k,l,m,n,P[MAX][MAX][MAX];
    double A[MAX][MAX][MAX],temp;
    bool flag;
    while(cin>>n) {
         for(i=1;i<=n;i++) for(j=1;j<=n;j++) {P[i][j][1]=i;if(i==j) A[i][j][1]=1.0; else cin>>A[i][j][1];}
         for(i=1;i<=n;i++) for(j=1;j<=n;j++) for(k=2;k<=n;k++) {A[i][j][k]=0;P[i][j][k]=-1;}
         for(k=2;k<=n;k++)
                for(i=1;i<=n;i++)
                       for(j=1;j<=n;j++)
                              {
                               for(l=1;l<k;l++)
                                  {
                                   for(m=1;m<=n;m++)
                                      {
                                       temp=(A[i][m][l]*A[m][j][k-l]);
                                       if(A[i][j][k]<temp) {A[i][j][k]=temp;P[i][j][k]=P[m][j][k-l];}
                                      }
                                  }
                              }
         flag=false;
         for(k=2;k<=n;k++) {
                            for(i=1;i<=n;i++) if(A[i][i][k]>1.01) {flag=true;break;}
                            if(flag) break;
         }
         if(!flag) cout<<"no arbitrage sequence exists\n";
         else {
               print_path(P,i,i,k);cout<<endl;
              }
    }
    return 0;
}
