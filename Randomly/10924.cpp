#include<iostream>
using namespace std;
int main()
{
    int s = 0,i,j;
    char c;
    bool sieve[1000] = {0};
    for(i = 2;i<=31;i++)
    {
          for(j = i*i;j<1000;j +=i)
          sieve[j] = 1;
    }
    
    while((c = getchar())!= EOF)
    {
             if(c != '\n')
             {
                  if(isupper(c))s += (c -'A' + 27);
                  else
                  s += (c - 'a'+1);
             }
             else
             {
                 if(sieve[s] == 0) cout<<"It is a prime word.\n";
                 else cout<<"It is not a prime word.\n";
                 s = 0;
             }
    }
    return 0;
}
             
