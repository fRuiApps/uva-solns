#include<iostream>
using namespace std;
#define MAX 1000001
int SOD(int n)
{
    int s=0;
    while(n)
    {
            s+=n%10;
            n=n/10;
    }
    return s;
}
main()
{
      bool A[MAX]={0};
      int i,t;
      for(i=1;i<MAX;i++)
      {t=SOD(i);if((i+t)<=1000000) A[i+t]=1;}
      for(i=1;i<MAX;i++)
      if(A[i]==0) cout<<i<<endl;
}
