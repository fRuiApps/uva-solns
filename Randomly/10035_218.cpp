#include<iostream>
using namespace std;
int main()
{
     unsigned long  n1,n2,c,c0,op = 0;
     while(cin>>n1>>n2 &&( n1 != 0 || n2 != 0))
     {
           c0 = 0;op = 0;
           while(n1 > 0 || n2 > 0)
           {
                 c = 0;
                 c = n1%10 + n2%10 + c0; 
                 if(c > 9) 
                 {
                     op++;
                     c0 = 1;
                 }
                 n1 /= 10; n2 /= 10;
           }      
           if(op == 0)  
           cout<<"No carry operation."<<endl;
           else if(op == 1)
           cout<<"1 carry operation."<<endl;
           else
           cout<<op<<" carry operations."<<endl;
     }
     return 0;
} 
            
