#include<stdio.h>
#include<math.h>
int main()
{
    int H,n,i,N=0;
    float t,a,b;
    while(1)
    {
     scanf("%d %d",&H,&n);
     if(H==0) break;
     for(i=1;i<=32;i++){
     t=1.0/i;
     a=pow(n,t);b=pow(H,t)-1;
     if(a==b) {N=(int)pow(n,t);break;}
     }
     printf("%d %d\n",(int)((n-1)/(N-1)),N*H-N*n+H);
    }
    return 0;
}
