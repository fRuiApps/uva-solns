#include<stdio.h>
int main()
{
    int H,M;
    double d;
    while(1)
    {
     scanf("%d:%d",&H,&M);
     if(H==0) break;
     d=fabs(H*30-5.5*M);
     printf("%0.3f\n",(d>180)?(360-d):d);
    }
    return 0;
}
