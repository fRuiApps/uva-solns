#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int N,i,c,la,lb,j,t,s;
    char A[201],B[201];
    bool f;
    cin>>N;
    for(i=1;i<=N;i++)
    {
     cin>>A>>B;
     la=strlen(A)-1;lb=strlen(B)-1;
     if(la>lb) {for(j=lb+1;j<=la;j++) B[j]='0'; B[j]='\0'; lb=la;}
     else if(lb>la) {for(j=la+1;j<=lb;j++) A[j]='0';A[j]='\0'; la=lb;}
     c=f=0;
     for(j=0;j<=la;j++) {
     s=(A[j]-'0'+B[j]-'0'+c);
     t=s%10;
     if(t>0) f=true;
     if(f) cout<<t;
     c=s/10;}
     if(c>0) cout<<c;
     cout<<endl;
    }
    return 0;
}
