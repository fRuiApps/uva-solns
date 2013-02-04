#include<iostream>
using namespace std;
int ref[110][110];
int longestRun(int A[][110],int R,int C,int r,int c)
{
    int l1,l2,l3,l4,m=0;
    l1=l2=l3=l4=1;
    if(!ref[r][c]) {
                    if(r-1>=0 && A[r-1][c]<A[r][c]) l1+=longestRun(A,R,C,r-1,c);
                    if(c-1>=0 && A[r][c-1]<A[r][c]) l2+=longestRun(A,R,C,r,c-1);
                    if(r+1<R  && A[r+1][c]<A[r][c]) l3+=longestRun(A,R,C,r+1,c);
                    if(c+1<C  && A[r][c+1]<A[r][c]) l4+=longestRun(A,R,C,r,c+1);
                    if(m<l1) m=l1;if(m<l2) m=l2;if(m<l3) m=l3;if(m<l4) m=l4;
                    ref[r][c]=m;
    }
    return ref[r][c];
}
int main()
{
    char s[100];
    int R,C,i,j,max,k,N,A[110][110];
    cin>>N;
    for(i=0;i<N;i++) {
                      cin>>s>>R>>C;max=0;
                      for(j=0;j<R;j++) for(k=0;k<C;k++) {cin>>A[j][k];ref[j][k]=0;}
                      for(j=0;j<R;j++) for(k=0;k<C;k++) if(max<longestRun(A,R,C,j,k)) max=longestRun(A,R,C,j,k);
                      cout<<s<<": "<<max<<endl;
                     }
    return 0;
}
