#include<stdio.h>
int main()
{
    char status[151];
    int n,m,s,sum,i,j,f,c;
    while(1)
    {
     scanf("%d",&n);
     f=0;
     if(n==0) break;
     for(m=2;;m++)
     {
      for(i=0;i<n;i++) status[i]=0;i=s=c=0;
      while(1)
      {
       if(status[i]==0 && c%m==0) {
        status[i]=1;s++;
        if(i==1) {if(s==n) f=1;
                  break;
                 }
        }
        i=(i+1)%n;
        if(status[i]==0) c++;
       }
      if(f==1) {printf("%d\n",m);break;}
      }
    }
    return 0;
}
