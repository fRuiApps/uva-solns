#include<iostream>
using namespace std;
  
bool is_vowel(char c)
{
     if(c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'O' || c == 'U' || c == 'i' || c == 'I' )
     return 1;
     else return 0;
}
     
bool is_letter(char c)
{
              if((c>=65 && c<=90) || (c>=97 && c<= 122))  return 1;
              return 0;
}     


void process(char st)
{
     char c;
     string disp = "";
     if(is_vowel(st)) 
     {
         while((c = getchar())!=EOF && is_letter(c)) disp += c;
         cout<<st<<disp<<"ay"<<c;
     }
     else
     {
         while((c = getchar())!=EOF && is_letter(c)) disp += c;
         cout<<disp<<st<<"ay"<<c;
     }
}

int main()
{
    char c;
    int i,len;
    while((c = getchar())!=EOF)
    {                 
         if(is_letter(c)) process(c);
         else putchar(c);
    }
    return 0;
}
                 
         

                 
             
