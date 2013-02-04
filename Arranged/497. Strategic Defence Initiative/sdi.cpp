#include<stdio.h>
void printSeq(int *A,int *Ref,int &st)
{
    if(Ref[st]==-1) printf("%d\n",A[st]);
    else {printSeq(A,Ref,Ref[st]);
          printf("%d\n",A[st]);
    }
} 
void LIS(int *A,int l)
{
    int Ref[l],L[l],m=1,st=0,i,j;
    Ref[0]=-1;st=i;L[0]=1;
    for(i=1;i<l;i++)
    {
     L[i]=1;Ref[i]=-1;
     for(j=0;j<i;j++) if((A[i]>A[j]) && (L[i]<(L[j]+1))) {L[i]=L[j]+1;Ref[i]=j;}
     if(m<L[i]) {m=L[i];st=i;}
    }
    printf("Max hits: %d\n",m);
    printSeq(A,Ref,st);
} 
int main()
{
    int N=0,A[1000],i,j,k,f=0;
    char c;
    while((c=getchar())!='\n') N=N*10+c-'0';
    c=getchar();
    for(i=1;i<=N;i++) 
    {
     j=0;A[j]=0;
     while(1) {c=getchar(); if(c=='\n' || c==EOF) {j++;A[j]=0;} else A[j]=A[j]*10+c-'0'; if(c==EOF || A[j-1]==0) break;}
     if(A[j]==0) j--;
     if(f) printf("\n"); else f=1;
     LIS(A,j);
    }
    return 0;
}
