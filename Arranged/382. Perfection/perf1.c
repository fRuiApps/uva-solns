#include<stdio.h>
int main()
{
    int N,i,s;
    printf("PERFECTION OUTPUT\n");
    while(1)
    {
     scanf("%d",&N);
     if(!N) break;
     s=0;
     for(i=1;i<=N/2;i++) if(N%i==0) s+=i;
     printf("%5d  %s\n",N,(s==N)?"PERFECT":((s<N)?"DEFICIENT":"ABUNDANT"));
    }
    printf("END OF OUTPUT\n");
    return 0;
}
