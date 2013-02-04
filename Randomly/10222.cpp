#include<iostream>
using namespace std;
int main()
{
   char array[100] = "`12345567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./",c;
   int i,l; 
   l = strlen(array); 
   while((c = getchar())!= EOF)
   {
                          
                     if(c != '\n')
                     {
                          if(isupper(c)) c += 32;
                          if(isspace(c)) cout<<" ";
                          if(c == '\\') cout<<"]";
                          else
                          {
                              for(i =0;i<l;i++)
                              if(array[i] == c) cout<<array[i-2];
                          }
                     }
                     else
                     cout<<endl;
   }
   return 0;
}
                     
