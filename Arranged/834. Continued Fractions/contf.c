#include<stdio.h>
int main()
{
    int N,D,t,f;
    while(scanf("%d %d",&N,&D)!=EOF)
    {
     f=1;
     printf("[%d;",N/D);
     while(1){
              N%=D;
              if(f) f=0; else printf(",");
              if(N==1) {printf("%d]\n",D);break;}
              t=N;N=D;D=t;
              printf("%d",N/D);
             } 
    }
}
