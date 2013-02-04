#include<stdio.h>
int main()
{
    int N=0,i,k,Ref[10000],j,f=0;
    char numbers[10000][100],c;
    while((c=getchar())!='\n') N=N*10+c-'0';
    for(i=1;i<=N;i++)
    {
     c=getchar();
     k=0;
     for(j=0;j<1000;j++) Ref[j]=0;
     while(1) {
        c=getchar();
        if(c==' ' || c=='\n') k++; else Ref[k]=Ref[k]*10+c-'0';
        if(c=='\n') break;
     }
     for(j=0;j<k;j++) scanf("%s",numbers[Ref[j]]);
     if(!f) f=1; else printf("\n");
     for(j=1;j<=k;j++) printf("%s\n",numbers[j]);
     while((c=getchar())!='\n');
    }
    return 0;
}
