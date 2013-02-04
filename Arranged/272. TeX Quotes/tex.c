#include<stdio.h>
int main()
{
    char A[3]="`'",c;
    int p=0;
    while((c=getchar())!=EOF)
    if(c=='"') {printf("%c%c",A[p],A[p]);p=(p+1)%2;} else printf("%c",c);
    return 0;
}
