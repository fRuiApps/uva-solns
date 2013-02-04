#include<iostream>
using namespace std;
void filter(bool *s,int *u,int nu,int n,char c)
{
    int i;
    bool s1[101];
    for(i=1;i<=n;i++) s1[i]=false;
    if(c=='=') for(i=1;i<=2*nu;i++) s[u[i]]=false;
    else if(c=='<' || c=='>') { for(i=1;i<=2*nu;i++) s1[u[i]]=true;
                                for(i=1;i<=n;i++) s[i]=s[i]&&s1[i];
    }
    //for(i=1;i<=n;i++) cout<<s[i];
    //cout<<endl;
}
int main()
{
    int n,i,j,x,k,m,u[101],nu,s;
    bool sieve[101],f=false;
    char c;
    cin>>m;
    for(i=1;i<=m;i++)
    {
     cin>>n>>k;
     for(j=1;j<=n;j++) sieve[j]=true;s=0;
     for(j=1;j<=k;j++)
     {
      cin>>nu;
      for(x=1;x<=2*nu;x++) cin>>u[x];
      cin>>c;
      //cout<<n<<" "<<nu<<" "<<c<<endl;
      filter(sieve,u,nu,n,c);
     }
     for(j=1;j<=n;j++) if(sieve[j]) {s++;x=j;}
     if(f) cout<<endl; else f=true;
     if(s==1) cout<<x<<endl;
     else cout<<"0\n";
    }
    return 0;
}
