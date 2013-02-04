#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    char str[1000];
   gets(str);
    {for(int i = 0;str[i];i++)
    str[i] = str[i] - 7;
    puts(str);}
    getch();
    return 0;
}
