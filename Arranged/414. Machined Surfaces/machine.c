#include<stdio.h>
int main()
{
    int N,i,A[13],m,s;
    char c;
    while(1)     {
     scanf("%d",&N);
     if(N==0) break;
     m=30;
     for(i=0;i<=N;i++) A[i]=0;
     for(i=0;i<=N;i++) 
     {
      while((c=getchar())!='\n') {if(c==' ') A[i]++;}
      if(i>0 && m>A[i]) m=A[i];
     }
     s=0;
     for(i=1;i<=N;i++) s+=(A[i]-m);
     printf("%d\n",s);
    }
    return 0;
}
