#include<iostream>
using namespace std;
char A[10010][10010];
void printrev(char * s,int l)
{
     int i;
     for(i=l-1;i>=0;i--) cout<<s[i];
}
int main()
{
    int N,i,j,n,L[100];
    char c,f=0;
    while(true) {
    i=j=0;
    while(true)
     {
      c=getchar();
      if(c==EOF) {f=1;break;}
      if(c==' ') {A[i][j]='\0';L[i]=j;i++;j=0;}
      else if(c!='\n' && c!=EOF) {A[i][j++]=c;}
      else if(c=='\n' || c==EOF) {A[i][j]='\0';L[i]=j;i++;break;}
     }
     if(f) break;
     n=i;
     for(i=0;i<n;i++) {printrev(A[i],L[i]);if(i<(n-1)) cout<<" ";}
     cout<<endl;
     if(c==EOF) break;
    }
    return 0;
}
