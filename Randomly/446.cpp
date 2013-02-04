
#include<iostream>
using namespace std;
int main()
{
    
    int num1 ,sum,num2,i,n;
    char op;
    string s1,s2,base = "0123456789ABCDEF";
    cin>>n;
    while(n--)
    {
              bool ans1[12] = {0};
              
              num1 = num2 = sum = 0;
              cin>>s1>>op>>s2;
              for(i =0;s1[i];i++)
              num1 = num1*16 + base.find(s1[i]) ;
              
              for(i =0;s2[i];i++)
              num2 = num2*16 + base.find(s2[i]) ;
              
              if(op == '+')
              sum = num1+num2;
              else
              sum = num1 - num2;
              int cnt =  11;
              while(num1 != 0)
              {
                        ans1[cnt--] = num1%2;  
                        num1 /= 2;
                        
              }
              cout<<"0";for(i = 0;i<12;i++)cout<<ans1[i];cnt = 11;
              
              bool ans2[12] = {0};
              
              
              if(op == '+')
              cout<<" + ";
              else
              cout<<" - ";
              while(num2 != 0)
              {
                        ans2[cnt--] = num2%2;  
                        num2 /= 2;
              }
              cout<<"0";
              for(i = 0;i<12;i++)cout<<ans2[i];
              cout<<" = "<<sum<<endl;
    } 
    return 0;
}
