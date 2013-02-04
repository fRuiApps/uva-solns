#include<iostream>
using namespace std;
int main()
{
    int S[1001],B[1001],N,sp,i,pa,j;
    bool f,fl=true;
    while(true){
    cin>>N; if(N==0) break;
    //if(fl) fl=false; else cout<<endl;
    while(true) {
    sp=-1;pa=1;f=true;
    for(i=0;i<N;i++) 
    {
     cin>>B[i];
     if(B[i]==0) {cout<<endl;break;}
     if(B[i]==pa) pa++;
     else if(B[i]>pa) {for(j=pa;j<B[i];j++) S[++sp]=j;pa=B[i]+1;}
     else if(B[i]==S[sp]) sp--;
     else f=false;
    }
    if(i==0) break;
    if(f) cout<<"Yes\n"; else cout<<"No\n";
    }
}
    return 0;
}
