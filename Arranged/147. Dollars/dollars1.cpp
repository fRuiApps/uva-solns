#include<stdio.h>
#define MAX 30001
int main()
{
    long long ways[MAX]={0};
    int i,amtc;
    char amt[7];
    ways[0]=1;
    for(i=5;i<=30000;i+=5) ways[i]+=ways[i-5];
    for(i=10;i<=30000;i+=5) ways[i]+=ways[i-10];
    for(i=20;i<=30000;i+=5) ways[i]+=ways[i-20];
    for(i=50;i<=30000;i+=5) ways[i]+=ways[i-50];
    for(i=100;i<=30000;i+=5) ways[i]+=ways[i-100];
    for(i=200;i<=30000;i+=5) ways[i]+=ways[i-200];
    for(i=500;i<=30000;i+=5) ways[i]+=ways[i-500];
    for(i=1000;i<=30000;i+=5) ways[i]+=ways[i-1000];
    for(i=2000;i<=30000;i+=5) ways[i]+=ways[i-2000];
    for(i=5000;i<=30000;i+=5) ways[i]+=ways[i-5000];
    for(i=10000;i<=30000;i+=5) ways[i]+=ways[i-10000];
    while(1) {
        scanf("%s",amt);
        amtc=0;
        for(i=0;amt[i]!='\0';i++) if(amt[i]!='.') amtc=amtc*10+amt[i]-'0';
        if(!amtc) break;
        printf("%6s%17lld\n",amt,ways[amtc]);
    }
    return 0;
}

