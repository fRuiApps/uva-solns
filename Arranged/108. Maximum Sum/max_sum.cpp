#include<iostream>
using namespace std;
int sum(int M[][101],int x,int y,int z)
{
    int i,s=0;
    for(i=x;i<=y;i++) s+=M[z][i];
    return s;
}
int findMax(int M[][101],int x,int y,int l)
{
    int Ref[l],m=0,i;
    Ref[0]=sum(M,x,y,0); m=Ref[0];
    for(i=1;i<l;i++) {
                      Ref[i]=sum(M,x,y,i)+((Ref[i-1]>0)?Ref[i-1]:0);
                      if(m<Ref[i]) m=Ref[i];
    }
    return m;
}
int main()
{
    int i,j,k,x,y,l,m=0,M[101][101];
    cin>>l;
    for(i=0;i<l;i++) for(j=0;j<l;j++) cin>>M[i][j]; 
    for(k=1;k<=l;k++) {
                        for(x=0;x<=(l-k);x++) {
                                               y=x+k-1;
                                               if(m<findMax(M,x,y,l)) m=findMax(M,x,y,l);
                        }
     }
    cout<<m<<endl; 
    return 0;
}
