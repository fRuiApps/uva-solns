#include<stdio.h>
int main()
{
    char c;
    int s=0,i;
    while((c=getchar())!=EOF)
    {
     if(c=='\n' || c=='!') {printf("\n");s=0;}
     else if(c=='b') {for(i=0;i<s;i++) printf(" ");s=0;}
     else if(c>='A' && c<='Z' || c=='*') {for(i=0;i<s;i++) printf("%c",c);s=0;}
     else s+=c-'0';
    }
    return 0;
}
