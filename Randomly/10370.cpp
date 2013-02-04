#include<cstdio>
#include<iostream>
#define for(i,n) for(i =0;i<n;i++)
using namespace std;
int main()
{
   int avg,n,i,sum,*marks,c;
   float per;
   
   cin>>c;
   while(c--)
   {
             sum = per = 0;
             cin>>n;
             marks = new int[n];
             for(i,n)
             {
                     cin>>marks[i];
                     sum += marks[i];
             }
             avg = sum/n;
             for(i,n)
             {
                     if(marks[i]>avg)
                     per++;
             }
            per *= 100;
             per /= n;
             printf("%2.3f",per);
             cout<<"%"<<endl;
   }
             
   return 0;
} 
