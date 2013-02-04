#include<iostream>
using namespace std;
unsigned long int reverse(unsigned long int);
int main()
{
    unsigned long int i,a,n,flag = 0,c = 0,s;
    while(cin>>n)
    {
                for(i = 0;i<n;i++)
                 {
                      cin>>a;
                      if(a == 0)
                      cout<<"0 0"<<endl;
                      else
                      if( a == reverse(a) ) 
                      cout<<"0 "<<a<<endl;
                      else
                      {
                          while(flag == 0)
                             {
                                 s  = a + reverse(a);
                                 c++;
                                 if(reverse(s) == s) 
                                 flag = 1;
                                 a = s;
                             }
                             cout<<c<<" "<<a<<endl;
                      }
                      flag = c = 0;
                 }
    }
     return 0;
}
 
 unsigned long int reverse(unsigned long int a)
 {
          unsigned long int b;
          b = a%10;a = a/10;
          while(a!=0)
          {
                     b = (b*10) + (a%10);
                     a /= 10;
          }
          return b;
 } 
     
     
    
