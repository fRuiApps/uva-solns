#include<stdio.h>
int main(int argc,char *argv[])
{
    char c;
    while((c=getchar())!=EOF)
    printf("%c",((c=='\n'?c:(c-7))));
    return 0;
}
