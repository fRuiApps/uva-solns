#include<stdio.h>
#define MAX 30010
int main()
{
    int K,M,N,s,u[MAX],i,j,k,f=0,p,pos,t,A[MAX],S[MAX];
    /*unsigned int z=-1;
    printf("%u\n",z);*/
    scanf("%d",&K);
    for(i=0;i<K;i++) {
                      if(f) printf("\n"); else f=1;
                      scanf("%d %d",&M,&N);
                      for(j=0;j<M;j++) scanf("%d",&A[j]);
                      for(k=0;k<N;k++) scanf("%d",&u[k]);
                      p=s=0;
                      for(j=0;j<M&&p<N;j++) {
                                             while(u[p]==j) {printf("%d\n",S[p]);p++;}
                                             for(t=0;t<j;t++) if(A[j]<=S[t]) break;
                                             for(k=j;k>t;k--) S[k]=S[k-1];
                                             S[t]=A[j];
                                             /*for(k=0;k<=j;k++) printf("%d ",S[k]);
                                             printf("\n");*/
                                            }
                      for(;p<N;p++) printf("%d\n",S[p]);
                      /*printf("\n");*/
                     }
    return 0;
}
