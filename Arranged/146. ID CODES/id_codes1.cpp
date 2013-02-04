#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    char s[60]="",c;
    int l,i,j=0;
    while((c=getchar())!='#')
    {
     s[j++]=c;
     if(c=='\n') {s[j-1]='\0';j=0;} else continue;
     l=strlen(s);
     for(i=l-2;i>=0;i--) if(s[i]<s[i+1]) break;
     if(i==-1) cout<<"No Successor\n";
     else {
           next_permutation(s,s+l);
           cout<<s<<endl;
          }
    }
    return 0;
}
