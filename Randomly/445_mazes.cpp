#include<iostream>
using namespace std;
int main()
{
    char str;
    int i,num= 0;
    while((str = getchar()) != EOF)
    {
              if(str == '\n')
              printf("\n");
              if(isdigit(str))
              num += (int)str - 48;
              else
              if(str == '!')
              cout<<"\n";
              else
              if(str == 'b')
             {
                      for(i = 0;i<num;i++)
                      cout<<" ";
                      num = 0;
              }
              else
              {
                  for(i = 0;i<num;i++)
                  cout<<str;
                  num = 0;
              }
              
    }
    return 0;
}
