#include<iostream>
#include<string>
using namespace std;
int noPaths(bool unsafe[][1000],int &w,int &n)
{
    int M[100][100]={0},i,j;
    M[w][n]=1;
    M[w-1][n]=((unsafe[w-1][n]==true)?0:1);
    M[w][n-1]=((unsafe[w][n-1]==true)?0:1);
    for(i=n-2;i>=1;i--) M[w][i]=((unsafe[w][i]==true)?0:M[w][i+1]);
    for(i=w-2;i>=1;i--) M[i][n]=((unsafe[i][n]==true)?0:M[i+1][n]);
    for(j=(n-1);j>=1;j--) for(i=(w-1);i>=1;i--) M[i][j]=((unsafe[i][j]==true)?0:(M[i+1][j]+M[i][j+1]));
    return M[1][1];
}
int main()
{
    bool unsafe[1000][1000],flag=false;
    int i,j,k,l,w,n,c,t,f;
    string s;
    cin>>c;
    for(i=1;i<=c;i++)
    {
     cin>>w>>n;
     getline(cin,s);
     for(j=0;j<1000;j++) for(k=0;k<1000;k++) unsafe[j][k]=false;
     for(j=1;j<=w;j++)
     {
      t=f=0;getline(cin,s);l=s.length();
      for(k=0;k<=l;k++) {
                         if((s[k]==' ' || s[k]=='\0') && t>0) {f++; if(f>1) unsafe[j][t]=true; t=0;}
                         else t=t*10+s[k]-'0';
      }
     }
     if(flag==false) flag=true; else cout<<"\n";
     cout<<noPaths(unsafe,w,n)<<endl;
    }  
    return 0;
}
