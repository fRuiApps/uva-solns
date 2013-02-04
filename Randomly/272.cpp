#include<iostream>
using namespace  std;
int main()
{
    char c;
    bool quote = 0;
    while((c = getchar())!= EOF)
    {
             if(c != '\n')
             {
                  if(c == '"')
                  {
                       if(quote == 0)
                       {
                                cout<<"``";
                                quote = 1;
                       }
                       else
                       if(quote == 1)
                       {
                                cout<<"''";
                                quote = 0;
                       }
                  }
                  else
                  cout<<c;
             }
             else
             cout<<endl;
    }
    return 0;
}
