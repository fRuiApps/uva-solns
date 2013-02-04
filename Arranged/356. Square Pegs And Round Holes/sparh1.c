#include<stdio.h>
int main()
{
    int n,f,i,j,d,flag=0;
    while(scanf("%d",&n)!=EOF)  {
    f=0;d=2*n-1;
    for(i=1;i<n;i++)
    for(j=1;j<n;j++)
    if((i*i+j*j)<=(0.25*d*d)) f++; else break;
    if(flag==0) flag=1; else printf("\n");
    printf("In the case n = %d, %d cells contain segments of the circle.\nThere are %d cells completely contained in the circle.\n",n,(8*n-4),4*f);
    }   
    return 0;
}
