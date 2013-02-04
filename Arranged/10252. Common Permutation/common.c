#include<stdio.h>
int main()
{
    char c;
    int f1[130],f2[130],f[130],i,j,flag=0;
    while(1) {
    for(i=0;i<130;i++) f1[i]=f2[i]=f[i]=0;
    while(1) {
              c=getchar();
              if(c=='\n') break;
              if(c==EOF) {flag=1;break;} 
              f1[c]++;
    }
    if(!flag) {
               while(1) {c=getchar();if(c=='\n' || c==EOF) break;f2[c]++;}
    }
    else break;
    for(i=0;i<130;i++) f[i]=(f1[i]<=f2[i])?f1[i]:f2[i];
    for(i=0;i<130;i++) for(j=1;j<=f[i];j++) printf("%c",i);printf("\n");
    if(c==EOF) break;
    }
    return 0;
}
