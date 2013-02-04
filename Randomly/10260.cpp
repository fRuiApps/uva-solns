#include<iostream>
using namespace std;
int main()
{
    char array[100] = "01230120022455012623010202",c,last = 'z',present;
    while((c = getchar()) != EOF)
    {
             
             if(c != '\n')
             {
                  present = array[c - 'A'];
                  if(present != '0'  && last != present)
                  cout<<present;
                  last = present;
             }
             else
             {
                 cout<<endl;
                 last = '_';
             }
    }
    return 0;
}
    
