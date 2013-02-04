#include<iostream>
using namespace std;
int index(char A[][13],char * N,int n)
{
    int i;
    for(i=0;i<n;i++) if(strcmp(A[i],N)==0) return i;
}
int main()
{
    int i,j,k,n,l,sum[11],a;
    char names[11][13],s[13],t[13],f=0;
    while(cin>>n)
    {
        for(i=0;i<11;i++) sum[i]=0;
        for(i=0;i<n;i++) cin>>names[i];
        for(i=0;i<n;i++) {
            cin>>s;
            a=index(names,s,n);
            cin>>j>>k;
            if(k) sum[a]-=((j/k)*k);
            for(l=1;l<=k;l++) {cin>>t;sum[index(names,t,n)]+=(j/k);}
        }
        if(f) cout<<endl; else f=1;
        for(i=0;i<n;i++) cout<<names[i]<<" "<<sum[i]<<endl;
    }
    return 0;
}
