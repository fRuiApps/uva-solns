#include<stdio.h>
#include<string.h>
int pos(char[],char);
main()
{
      char st[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
      char t;
      while(1)
      {
       t=getchar();
       if(t==EOF) break;
       if(t==' ' || t=='\n')
       printf("%c",t);
       else printf("%c",st[pos(st,t)-1]);
      }
}
int pos(char A[],char c)
{
    int i;
    for(i=0;i<strlen(A);i++)
    if(A[i]==c)
    return i;
    return -1;
}
