#include<iostream>
#include<string.h>
using namespace std;
bool allOnes(char M[][26],int x,int y,int z)
{
    int i;
    for(i=x;i<=y;i++) if(M[z][i]=='0') return false;
    return true;
}
int findMax(char M[][26],int x,int y,int l)
{
    int Ref[l],m=0,i;
    if(allOnes(M,x,y,0)) {Ref[0]=(y-x+1); m=Ref[0];} else Ref[0]=0;
    for(i=1;i<l;i++) {
                      if(allOnes(M,x,y,i)) Ref[i]=Ref[i-1]+y-x+1; else Ref[i]=0;
                      if(m<Ref[i]) m=Ref[i];
    }
    return m;
}
int main()
{
    int c,i,j,k,x,y,t,l,m;
    bool f=false;
    char M[26][26];
    cin>>c;
    for(i=1;i<=c;i++)
    {
     cin>>M[0];l=strlen(M[0]);
     for(j=1;j<l;j++) cin>>M[j];m=0;
     if(f) cout<<endl; else f=true;
     for(k=1;k<=l;k++) {
                        for(x=0;x<=(l-k);x++) {
                                               y=x+k-1;
                                               if(m<findMax(M,x,y,l)) m=findMax(M,x,y,l);
                        }
     }
     cout<<m<<endl; 
    }
    return 0;
}
