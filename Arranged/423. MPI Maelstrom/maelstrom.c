#include<stdio.h>
#include<ctype.h>
#define MAX 110
#define INF 1<<25
int main()
{
    int n,i,j,A[MAX][MAX],m=0,k,v;
    char s[10];
    scanf("%d",&n);
    for(i=1;i<n;i++) for(j=0;j<i;j++) {scanf("%s",s);v=atoi(s);if(v) A[i][j]=v;else A[i][j]=INF;}
    for(i=0;i<n;i++) A[i][i]=0;
    for(i=0;i<n;i++) for(j=i+1;j<n;j++) A[i][j]=A[j][i];
    for(k=0;k<n;k++) for(i=0;i<n;i++) for(j=0;j<n;j++) if(A[i][j]>(A[i][k]+A[k][j])) A[i][j]=A[i][k]+A[k][j];
    for(i=0;i<n;i++) if(m<A[0][i]) m=A[0][i];
    printf("%d\n",m);
    return 0;
}

