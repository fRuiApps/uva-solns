#include<iostream>
#include<stack>
using namespace std;
int main()
{
    char c;
    stack<char>s;
    while((c = getchar())!= EOF)
    {
             if(c != ' ' && c != '\n') s.push(c);
             else
             {
                 while(!s.empty())
                 {
                    cout<<s.top();
                    s.pop();
                 }
                 cout<<c;
             }
    }
    return 0;
}
