#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
    int i,l,n,k;
    string s;
    while(true)
    {
     getline(cin,s);
     if(s=="0") break;
     l=s.length();k=1;n=0;
     for(i=l-1;i>=0;i--) {n=n+(s[i]-'0')*(pow(2,k)-1);k++;}
     cout<<n<<endl;
    }
    return 0;
}
