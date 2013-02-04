#include<stdio.h>
int minsteps[1001][1001];
int main()
{
    char str[1001];
    int T,i,j,l,m,t,k,x,y;
    for(i=0;i<1000;i++) minsteps[i][i]=0;
    scanf("%d",&T);
    for(i=1;i<=T;i++) {
        scanf("%s",str);
        l=strlen(str)-1;
        for(j=0;j<=l;j++) if(str[j]!=str[j+1]) minsteps[j][j+1]=1; else minsteps[j][j+1]=0;
        for(j=2;j<=l;j++)
            for(k=0;k<=l;k++)
                {
                    x=k;y=k+j;if(x>l || y>l) continue;
                    if(str[x]==str[y])
                        minsteps[x][y]=minsteps[x+1][y-1];
                    else {
                            m=2000;
                            t=1+minsteps[x+1][y];if(m>t) m=t;
                            t=1+minsteps[x+1][y-1];if(m>t) m=t;
                            t=1+minsteps[x][y-1];if(m>t) m=t;
                            minsteps[x][y]=m;
                         }
                }
        /*for(j=0;j<=l;j++) {for(k=0;k<=l;k++) printf("%3d",minsteps[j][k]);printf("\n");}*/
        printf("Case %d: %d\n",i,minsteps[0][l]);
    }
    return 0;
}
