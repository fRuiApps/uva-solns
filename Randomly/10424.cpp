#include<iostream>
using namespace std;
int main()
{
    int sum1,sum2,i;
    float sum11,sum22,temp;
    char a[200],b[200];
    char c;    
    while(gets(a)&&gets(b))
    {
    sum1 = sum2 = 0;
             for(i =0;a[i];i++)
             {
                   c = a[i];
                   if(islower(c))
                   sum1 += c - 'a'+1;
                   else if(isupper(c))
                   sum1 += c - 'A'+1;
             }
             for(i =0;b[i];i++)
             {
                   c = b[i];
                   if(islower(c))
                   sum2 += c - 'a'+1;
                   else if(isupper(c))
                   sum2 += c - 'A' + 1;
             }
             
             if(sum1 % 9 == 0  && sum1 != 0)sum1 = 9;else sum1 %= 9;       
             
             if(sum2%9 == 0 && sum2 != 0) sum2 = 9; else sum2 %= 9;             
             sum11 = sum1; sum22 = sum2;
            
             if(sum11<sum22) 
             {
                  temp = sum11;sum11 = sum22;sum22 = temp;
             }
             
             printf("%3.2f",(sum22*100)/sum11);
             cout<<" %\n";
             
    }

return 0;
}
                     
                     
                     
                    
