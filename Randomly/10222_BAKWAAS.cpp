#include<iostream>
using namespace std;
int main()
{
   char arrays[50] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./",c;
   char arrayl[50] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
   int i,l; 
   l = strlen(arrays);   
   while((c = getchar())!= EOF)
   {
                        
                     if(c != '\n')
                     {
                          if(c == ' ') cout<<" ";
                          else
                          {   if(isupper(c))
                              {for(i =0;i<l;i++)
                              {if(arrayl[i] == c) cout<<(char)(arrayl[i-2]+32);}}
                              else
                              {for(i =0;i<l;i++)
                              {if(arrays[i] == c) cout<<arrays[i-2];}}
                          }
                     }
                     else
                     cout<<endl;
   }
   return 0;
}
                     
