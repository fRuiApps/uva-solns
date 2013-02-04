#include<iostream>
#include<string.h>
using namespace std;
bool changeable(char *A,char *B,int a,int b)
{
     int i,n=0;
     if(a!=b) return false;
     for(i=0;i<a;i++) {if(A[i]!=B[i]) n++; if(n>1) return false;}
     return true;
}
bool idlable(char * A,char * B,int a,int b)
{
    int i=0;
    if((b-a)!=1) return false;
    while(A[i]==B[i]) i++;
    while(A[i]==B[i+1] && A[i]!='\0') i++;
    if(A[i]) return false;
    return true;
}
int main()
{
    char dict[10001][17],word[17],match[10001][17],L[10001];
    int N,i,j,k,m,n,t,p,x;bool f=false,g;
    cin>>N;
    for(i=1;i<=N;i++)
    {
     j=0;
     if(f) cout<<endl; else f=true;
     while(true) {
     cin>>dict[j];
     if(strcmp(dict[j],"#")==0) break;
     n=L[j]=strlen(dict[j]);
     j++;
     }
     m=0;
     while(true) {
     cin>>word;
     if(strcmp(word,"#")==0) break;
     m=strlen(word);p=0;g=false;
     for(k=0;k<j;k++)
     {
      n=L[k];
      if(strcmp(dict[k],word)==0) {cout<<word<<" is correct\n";g=true;}
      else if(changeable(dict[k],word,n,m) || idlable(word,dict[k],m,n) || idlable(dict[k],word,n,m)) strcpy(match[p++],dict[k]);
     }
     if(!g) {cout<<word<<":";
     for(k=0;k<p;k++) cout<<" "<<match[k];
     cout<<endl;}
     }
    }
    return 0;
}
