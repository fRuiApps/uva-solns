// a different recursive algo
#include<iostream>
using namespace std;
int main()
{
    string s,t;
    int no,i,j;
    while(cin>>s>>t)
    {
                    no = 0;
                    i = 0;j = 0;
                    while(t[i] && s[j])
                    {
                               if(s[j] == t[i])
                               {i++;j++;no++;}
                               else
                               i++;
                    }
                               
                    if(no == s.size())      
                    cout<<"Yes\n";
                    else
                    cout<<"No\n";
    }
    return 0;
}
