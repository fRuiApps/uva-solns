#include<stdio.h>
int main()
{
    int c;
    while(1){
    c=getchar();
    if(c==EOF) break;
    if(c=='\n') printf(","); else printf("%c",c);
}
    return 0;
}
