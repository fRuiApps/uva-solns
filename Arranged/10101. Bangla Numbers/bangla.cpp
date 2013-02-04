#include<iostream>
#include<stdio.h>
using namespace std;
void toBangla(long long);
int main()
{
    int c=1;
    long long s;
    while(cin>>s)
    {
     printf("%4d",c);
     cout<<".";c++;
     if(s==0) cout<<" "<<s; else toBangla(s);
     cout<<endl;
    }
    return 0;
}
void toBangla(long long s)
{
     if((s/100)==0 && s!=0)
     cout<<" "<<s;
     else {
           if((s/10000000)!=0)
           {
            toBangla(s/10000000);
            cout<<" kuti";
            toBangla(s%10000000);
           }
           else if((s/100000)!=0)
           {
            toBangla(s/100000);
            cout<<" lakh";
            toBangla(s%100000);
           }
           else if((s/1000)!=0)
           {
            toBangla(s/1000);
            cout<<" hajar";
            toBangla(s%1000);
           }
           else if((s/100)!=0)
           {
            toBangla(s/100);
            cout<<" shata";
            toBangla(s%100);
           }
     }
}
