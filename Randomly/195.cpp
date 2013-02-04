#include<iostream>
using namespace std;
int main()
{
    string str,chk = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    int l,n,i;
    cin>>n;
    while(n--)
    {
              cin>>str;
              l = str.length();
              int num[l];
              for(i=0;i<l;i++)
              num[i] = chk.find(str[i]);
              sort(num,num+l);
              do
              {
                  for(i=0;i<l;i++)
                  cout<<chk[num[i]];
                  cout<<endl;
              }
              while(next_permutation(num,num+l))
              ;
    }
    return 0;
}
                                                
              
