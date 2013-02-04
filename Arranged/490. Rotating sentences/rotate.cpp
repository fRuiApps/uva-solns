#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char s[200][200],c;
    int i=0,m=0,j,k;
    bool status[200]={0};
    while(true)
    {
     c=getchar();
     if(c=='\n' || c==EOF) {s[i][j]='\0';if(m<strlen(s[i])) m=strlen(s[i]);i++;j=0;}
     else {s[i][j]=c;j++;}
     if(c==EOF) break;
    }
    if(strlen(s[i-1])==0) i--;
    for(k=0;k<m;k++)  {
                       for(j=(i-1);j>=0;j--) 
                       {
                        if(s[j][k]=='\0') status[j]=1;
                        if(!status[j]) cout<<s[j][k]; else cout<<" ";
                       }
                       cout<<endl;
    }
    return 0;
}
