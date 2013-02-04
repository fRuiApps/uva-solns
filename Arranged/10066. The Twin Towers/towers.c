#include<stdio.h>
#define MAX 110
int LCS(int * A,int * B,int a,int b)
{
    int L[MAX][MAX],i,j;
    for(i=0;i<=a;i++) L[i][0]=0;
    for(i=0;i<=b;i++) L[0][i]=0;
    for(i=1;i<=a;i++) for(j=1;j<=b;j++) L[i][j]=((A[i]==B[j])?(1+L[i-1][j-1]):((L[i][j-1]>L[i-1][j])?L[i][j-1]:L[i-1][j]));
    return L[a][b];
}
int main()
{
    int cases=0,i,A[MAX],B[MAX],a,b;
    while(1) {
        scanf("%d %d",&a,&b);
        if(a==0) break;
        for(i=1;i<=a;i++) scanf("%d",&A[i]);
        for(i=1;i<=b;i++) scanf("%d",&B[i]);
        cases++;printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",cases,LCS(A,B,a,b));
    }
    return 0;
}
