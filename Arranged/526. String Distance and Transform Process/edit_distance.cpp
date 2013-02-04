#include<iostream>
#define INF 1000
using namespace std;
int M[100][100],TD[100][100],NS[100][100];
int minCost(char * A,char * B,int &la,int &lb,int i,int j)
{
    if(M[i][j]!=INF) return M[i][j];
    int a,b,c;
    if(i==la && j==lb) return 0;
    else if(i==la) {M[i][j]=1+minCost(A,B,la,lb,i,j+1);TD[i][j]='i';NS[i][j]=1;}
    else if(j==lb) {M[i][j]=1+minCost(A,B,la,lb,i+1,j);TD[i][j]='d';NS[i][j]=10;}
    else if(A[i]==B[j]) {M[i][j]=minCost(A,B,la,lb,i+1,j+1);TD[i][j]='n';NS[i][j]=11;}
    else {
          a=1+minCost(A,B,la,lb,i,j+1);
          b=1+minCost(A,B,la,lb,i+1,j+1);
          c=1+minCost(A,B,la,lb,i+1,j);
          if(a<=b && a<=c) {M[i][j]=a;TD[i][j]='i';NS[i][j]=1;}
          if(b<=a && b<=c) {M[i][j]=b;TD[i][j]='r';NS[i][j]=11;}
          if(c<=a && c<=b) {M[i][j]=c;TD[i][j]='d';NS[i][j]=10;}
    }
    return M[i][j];
}
int main()
{
    char A[82],B[82];
    int i,j,la,lb,n,t;bool f=false;
    while(cin>>A>>B)
    {
     la=strlen(A);
     lb=strlen(B);
     for(i=0;i<100;i++) for(j=0;j<100;j++) {M[i][j]=INF;NS[i][j]=0;}
     if(f) cout<<endl; else f=true;
     cout<<minCost(A,B,la,lb,0,0)<<endl;
     i=j=n=t=0;
     while(NS[i][j]!=0)
     {
      switch (TD[i][j])
      {
             case 'i' : n++;
                        cout<<n<<" Insert "<<j+1<<","<<B[j]<<endl;
                        t=NS[i][j];
                        i+=t/10;j+=t%10;
                        break;
                        
             case 'd' : n++;
                        cout<<n<<" Delete "<<j+1<<endl;
                        t=NS[i][j];
                        i+=t/10;j+=t%10;
                        break;
                        
             case 'r' : n++;
                        cout<<n<<" Replace "<<j+1<<","<<B[j]<<endl;
                        t=NS[i][j];
                        i+=t/10;j+=t%10;
                        break;
                        
             default : t=NS[i][j];
                       i+=t/10;j+=t%10;
      }
      }
    }
    return 0;
}
