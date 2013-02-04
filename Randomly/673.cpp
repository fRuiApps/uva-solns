#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<char> s;
    char str[500];
    bool no;
    int i,l,ntc;
    cin>>ntc;
    getchar();
    while(ntc--)
    {
             while(!s.empty()) s.pop();
             cin.getline(str,500);   
             no  = false;   
             l = strlen(str);
             str[l] = '\0';
             for(i = 0;i<l;i++)
             {
                   if(str[i] == '(' || str[i] == '[') s.push(str[i]);
                   else
                   if(str[i] == ']' )
                   {
                             if(s.empty()) {no = true;break;}
                             else
                             if(s.top() != '[') {no = true;break;}
                             else
                             s.pop();
                   }
                   else
                   if(str[i] == ')' )
                   {
                             if(s.empty()) {no = true;break;}
                             else
                             if(s.top() != '(') {no = true;break;}
                             else
                             s.pop();
                   }          
             }
             if(no == true || !s.empty()) cout<<"No\n";
             else cout<<"Yes\n";
    }
    return 0;
}
    
