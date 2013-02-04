#include<stdio.h>
int main()
{
    int A[50],n,i,s,t,m,c=1;
    while(1)
    {
     scanf("%d",&n);
     if(n==0) break;
     s=m=0;
     for(i=0;i<n;i++) {scanf("%d",&A[i]);s+=A[i];}
     t=s/n;
     for(i=0;i<n;i++) if(A[i]>t) m+=(A[i]-t);
     printf("Set #%d\nThe minimum number of moves is %d.\n\n",c,m);
     c++;
    }
    return 0;
}
