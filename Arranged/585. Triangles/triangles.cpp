#include<iostream>
using namespace std;
bool allEqual(char T[][220],int i,int j,int k,char e)
{
     int x;
     for(x=j;x<=k;x++) if(T[i][x]!=e) return false;
     return true;
}
int main()
{
    char T[110][220],t[2];
    int n,Hd[110][220],Hd1[110][220],Hh[110][220],Hh1[110][220],s,e,i,j,L,l,k,c=0,m;
    while(true)
    {
     cin>>n;gets(t);c++;m=0;
     if(n==0) break;
     for(i=0;i<n;i++) gets(T[i]);
     if(T[n-1][n-1]=='-') Hd1[n-1][n-1]=1; else Hh1[n-1][n-1]=1;
     for(i=(n-2);i>=0;i--)
     {
      s=i;L=2*(n-i)-1;e=s+L-1;
      for(l=1;l<=L;l+=2)
      {
       for(j=s;j<=(s+l-1);j++)
       {
        k=j+l-1;
        if(j==k){
        if(T[i][j]=='-') Hd[i][j]=1;
        else Hh[i][j]=1;
        }
        else { 
        if(T[i][j]=='-'){
        if(allEqual(T,i,j,k,'-') && Hd1[j+1][(j+1)+(l-2)-1]>0) {Hd[j][k]=Hd1[j+1][(j+1)+(l-2)-1]+l;if(m<Hd[j][k]) m=Hd[j][k];}
        else Hd[j][k]=0;}
        else
        {if(allEqual(T,i,j,k,'#') && Hh1[j+1][(j+1)+(l-2)-1]>0) {Hh[j][k]=Hh1[j+1][(j+1)+(l-2)-1]+l;if(m<Hh[j][k]) m=Hh[j][k];}
        else Hh[j][k]=0;}  
        }
       }
      }
      for(j=0;j<110;j++) for(k=0;k<110;k++) {Hd1[j][k]=Hd[j][k];Hh1[j][k]=Hh[j][k];}
     }
     cout<<m<<endl;
    }
    return 0;
}
