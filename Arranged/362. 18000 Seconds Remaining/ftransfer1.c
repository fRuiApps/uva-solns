#include<stdio.h>
#include<math.h>
int main()
{
    int n,c,s,r,tc,d=0;
    while(1)
    {
     scanf("%d",&n);
     if(n==0) break;
     tc=c=s=0;
     d++;
     printf("Output for data set %d, %d bytes:\n",d,n);
     while(n)
     {
      scanf("%d",&r);
      n-=r;
      s+=r;
      c++;
      tc++;
      if(c==5) {printf("   Time remaining: ");
      if(s==0) printf("stalled\n"); else printf("%d seconds\n",(int)ceil((5.0*n)/s));c=s=0;}
     }
     printf("Total time: %d seconds\n\n",tc);
    }
    return 0;
}
