#include<stdio.h>
#include<math.h>
int main()
{    
 long double Y;
 int N,i;bool f=false;
 scanf("%d",&N);
 for(i=1;i<=N;i++) {
 scanf("%Lf",&Y);
 if(f) printf("\n"); else f=true;
 printf("%Lf %.0Lf\n",Y,sqrtl(Y));
 }
 return 0;
}
