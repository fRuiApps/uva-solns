#include<stdio.h>
int main()
{
    int c=0,A,L,n;
    long long B;
    while(1)
    {
     scanf("%d %d",&A,&L);
     if(A==-1) break;
     c++;n=1;B=A;
     while(1)
     {
      if(B&1) B=3*B+1; else B/=2;
      if(B<=L) n++;
      if(B==1 || B>L) break;
     } 
     printf("Case %d: A = %d, limit = %d, number of terms = %d\n",c,A,L,n);
    }
    return 0;
}
