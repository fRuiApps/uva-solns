#include<iostream>
using namespace std;
int main()
{
    int n,i;
   string str;
    cin>>n;
    for(i = 0;i<n;i++)
    {     
        cin>>str;
        if(str == "1" || str == "4" || str == "78") cout<<"+\n";
        else if(str[str.length()-2] == '3' && str[str.length()-1] == '5') cout<<"-\n";
        else if(str[0] == '1' && str[1] == '9' && str[2] == '0')  cout<<"?\n";
        else if(str[0] == '9' && str[str.length()-1] == '4') cout<<"*\n";
        else ;  
    }

    return 0;
}
                            
