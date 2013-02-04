#include<stdio.h>
int main()
{
      int n,s,d,a,b,i;
      scanf("%d",&n);
      for(i=1;i<=n;i++)
      {
       scanf("%d %d",&s,&d);
       a=s+d;
       b=s-(a/2);
       if(!((a%2)==0 && (a/2 >=0) && (b>=0)))
       printf("impossible\n");
       else printf("%d %d\n",a/2,b);
      }
      return 0;
}
