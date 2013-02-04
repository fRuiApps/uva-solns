#include<stdio.h>
int main()
{
    int c,b;
    while(scanf("%d%d",&c,&b) != EOF)
    printf("%d\n",(c+((c-1)/(b-1)))); 
    return 0;
}
