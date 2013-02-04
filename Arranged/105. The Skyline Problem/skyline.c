#include<stdio.h>
# define MAX 20002
int main()
{
    int arr[MAX]={0},E=0,L,R,H,i,j,t,f=0;
    while((scanf("%d %d %d",&L,&H,&R))!=EOF)
    {
     for(i=L;i<R;i++) if(H>arr[i]) arr[i]=H;
     if(E<R) E=R;
    }
    for(i=0;arr[i]==0;i++);
    for(;i<=E;i++)
    {
     t=arr[i];
     if(!f) f=1; else printf(" ");
     printf("%d %d",i,t);
     while(arr[i]==t) i++;i--;
    }
    printf("\n");
    return 0;
}
