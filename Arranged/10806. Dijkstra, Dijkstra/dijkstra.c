#include<stdio.h>
#define INF 200000
int main()
{
    int d1,d2,p[101],w[101][101],i,j,k,l,n,m,d[101],queue[101],qs,min,x,p1;
    while(1) {
              scanf("%d",&n);if(n==0) break;scanf("%d",&m);qs=n;
              for(i=1;i<=n;i++) {d[i]=(i==1)?0:INF;p[i]=0;queue[i]=1;for(j=1;j<=n;j++) w[i][j]=(i==j)?0:INF;}
              for(i=1;i<=m;i++) {scanf("%d %d %d",&j,&k,&l);w[j][k]=w[k][j]=l;}
              while(qs) {
                         min=INF;
                         for(i=1;i<=n;i++) if(queue[i]&&d[i]<min) {min=d[i];x=i;}
                         queue[x]=0;qs--;
                         for(i=1;i<=n;i++) if(queue[i]&&(d[i]>(d[x]+w[x][i]))) {d[i]=(d[x]+w[x][i]);p[i]=x;}
                        }
              d1=d[n];p1=n;
              while(p1!=1) {w[p[p1]][p1]=INF;p1=p[p1];}
              for(i=1;i<=n;i++) {d[i]=(i==1)?0:INF;p[i]=0;queue[i]=1;}
              qs=n;
              while(qs) {
                         min=INF;
                         for(i=1;i<=n;i++) if(queue[i]&&d[i]<min) {min=d[i];x=i;}
                         queue[x]=0;qs--;w[p[x]][x]=INF;
                         for(i=1;i<=n;i++) if(queue[i]&&(d[i]>(d[x]+w[x][i]))) {d[i]=(d[x]+w[x][i]);p[i]=x;}
                        }
              d2=d[n];
              if((d1+d2)<INF) printf("%d\n",d1+d2); else printf("Back to jail\n");
             }
    return 0;
}
