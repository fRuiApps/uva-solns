#include<stdio.h>
int main()
{
    int N,L,A[51],i,j,k,t,x,s;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
     scanf("%d",&L);
     for(j=0;j<L;j++) scanf("%d",&A[j]);
     s=0;
     for(k=0;k<(L-1);k++)
     for(x=k+1;x<L;x++) if(A[k]>A[x]) {t=A[k];A[k]=A[x];A[x]=t;s++;}
     printf("Optimal train swapping takes %d swaps.\n",s);
    }
    return 0;
} 
