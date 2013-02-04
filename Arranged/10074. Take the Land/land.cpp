#include<iostream>
#define MAX 110
using namespace std;
int allZeros(bool A[][MAX],int r,int i,int j)
{
     int k;
     for(k=i;k<=j;k++) if(A[r][k]) return 0;
     return (j-i+1);
}
int max_area(bool A[][MAX],int i,int j,int R)
{
    int k,m,armax[MAX],t;
    m=armax[0]=allZeros(A,0,i,j);
    for(k=1;k<R;k++) {
                      t=allZeros(A,k,i,j);
                      if(t) armax[k]=armax[k-1]+t; else armax[k]=0;
                      if(m<armax[k]) m=armax[k];
                     }
    return m;
}
int main()
{
    int i,j,R,C,m,w,s;
    bool A[MAX][MAX];
    while(true) {
                      cin>>R>>C;
                      if(R==0) break;
                      m=0;
                      for(i=0;i<R;i++) for(j=0;j<C;j++) cin>>A[i][j];
                      for(w=1;w<=C;w++) {for(i=0;i<(C-w+1);i++) {j=i+w-1;s=max_area(A,i,j,R);if(m<s) m=s;}}
                      cout<<m<<endl;
    }
    return 0;
}
