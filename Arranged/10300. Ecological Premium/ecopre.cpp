#include<iostream>
using namespace std;
int main()
{
 int n,e,i,j,a,b,c;
 long long s,t;
 cin>>n;
 for(i=1;i<=n;i++)
 {
  s=0;
  cin>>e;
  for(j=1;j<=e;j++)
  {
   cin>>a>>b>>c;
   t=(long long)a*c;
   s+=t;
  }
  cout<<s<<endl;
 }
 return 0;
}
