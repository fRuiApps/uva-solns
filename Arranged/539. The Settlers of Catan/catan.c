#include<stdio.h>
char visited[30][30],path[30][30];
int longest_path(int st,int n)
{
    int p=0,t,i;
    for(i=0;i<n;i++)
        if(path[st][i] && !visited[st][i]) {visited[st][i]=visited[i][st]=1;t=1+longest_path(i,n);if(p<t) p=t;visited[st][i]=visited[i][st]=0;}
    return p;
}
int main()
{
    int n,m,i,j,a,b,max,t,st;
    while(1) {
        scanf("%d %d",&n,&m);
        if(n==0) break;
        for(i=0;i<n;i++) for(j=0;j<n;j++) path[i][j]=0;
        for(i=0;i<m;i++) {scanf("%d %d",&a,&b);path[a][b]=path[b][a]=1;}
        max=0;
        for(i=0;i<n;i++) {t=longest_path(i,n);if(t>max) {max=t;st=i;}}
        printf("%d\n",max);
    }
    return 0;
}
