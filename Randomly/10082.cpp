#include<iostream>
using namespace std;
int main()
{
   char array[50] = "`1234567890-=QQWERTYUIOP[]\\AASDFGHJKL;'ZXCVBNM,./",c;
   int i,l; 
   l = strlen(array);   
   while((c = getchar())!= EOF)
   {
                        
                     if(c != '\n')
                     {
                          if(c == ' ') cout<<" ";
                          //else
                          //if(c == '\\')
                          //cout<<']';
                          else
                          {   
                              for(i =0;i<l;i++)
                              if(array[i] == c) cout<<array[i-1];
                          }
                     }
                     else
                     cout<<endl;
   }
   return 0;
}
                     
