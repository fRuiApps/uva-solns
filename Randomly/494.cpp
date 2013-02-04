#include<iostream>
using namespace std;
int main()
{
char c,prev = ' ';
long word = 0;
while((c=getchar())!=EOF)
{
if(c != '\n')
{
if(isalpha(c)&& (!isalpha(prev)))
{word++; //cout<<c;
}
prev = c;
//cout<<prev;
}
else
{
cout<<word<<endl;
word = 0;
prev = ' ';
}
}
return 0;

}
