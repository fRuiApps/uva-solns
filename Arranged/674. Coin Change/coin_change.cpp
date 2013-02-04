#include<stdio.h>
int main()
{
    int ways[7490]={1},i,n;
    for(i=1;i<=7489;i++) ways[i]+=ways[i-1];
    for(i=5;i<=7489;i++) ways[i]+=ways[i-5];
    for(i=10;i<=7489;i++) ways[i]+=ways[i-10];
    for(i=25;i<=7489;i++) ways[i]+=ways[i-25];
    for(i=50;i<=7489;i++) ways[i]+=ways[i-50];
    while(scanf("%d",&n)!=EOF) printf("%d\n",ways[n]);
    return 0;
}
