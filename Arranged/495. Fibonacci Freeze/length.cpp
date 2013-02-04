#include<stdio.h>
int main()
{
    char c;
    int n=0;
    while((c=getchar())!=EOF) n++;
    printf("%d\n",n);
    return 0;
}
