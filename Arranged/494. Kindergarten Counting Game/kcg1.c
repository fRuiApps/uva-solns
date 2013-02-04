#include<stdio.h>
int isLetter(char c) {return (c>='A' && c<='Z' || c>='a' && c<='z');}
int main()
{
    int n=0;
    char t,c;
    while((c=getchar())!=EOF)
     if(c=='\n') {printf("%d\n",n);n=t=0;}
     else {if(!isLetter(c) && isLetter(t)) n++; t=c;}
    return 0;
}
