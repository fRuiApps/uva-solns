#include<stdio.h>
int main()
{
    int n,m,c,i,j,s,isRunning[21],amperes[21],blow,n1=0,Max;
    while(1) {
        scanf("%d %d %d",&n,&m,&c);
        if(n==0) break;
        s=0;blow=0;n1++;Max=0;
        for(i=1;i<=n;i++) isRunning[i]=amperes[i]=0;
        for(i=1;i<=n;i++) scanf("%d",&amperes[i]);
        for(i=1;i<=m;i++) {
            scanf("%d",&j);
            if(isRunning[j]==0) {isRunning[j]=1;s+=amperes[j];}
            else {isRunning[j]=0;s-=amperes[j];}
            if(Max<s) Max=s;
            if(s>c) blow=1;
        }
        if(blow) printf("Sequence %d\nFuse was blown.\n\n",n1);
        else printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",n1,Max);
    }
    return 0;
}
