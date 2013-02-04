#include<stdio.h>
#include<math.h>
int main()
{
    int N,i,f,K,inc;
    while(1) {
        scanf("%d",&N);
        if(N==0) break;
        printf("%d = ",N);
        if(N<0) {printf("-1 x ");N=-N;}
        i=2;f=0;inc=1;
        while(i<=sqrt(N)) if((N%i)==0) {
                                 if(f) printf(" x "); else f=1;
                                 printf("%d",i);
                                 N/=i;
                               }
                    else {i+=inc;if(inc==1) inc=2;}
        if(f) printf(" x "); else f=1;
        printf("%d\n",N);
    }
    return 0;
}
