#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
bool isGood(char * S)
{
     int l=strlen(S),i,s=0,s1=0,c=0,t;
     for(i=0;i<l;i++)
     if(S[i]>='0' && S[i]<='9' || c==9 && S[i]=='X') {t=(S[i]=='X')?10:(S[i]-'0');c++;s+=t;s1+=s;}
     else if(S[i]!='-' && S[i]!=' ') return false;
     if(c==10 && s1%11==0) return true;
     return false;
}
void display(char * S)
{
     int i,l=strlen(S),s,e;
     s=0;e=l-1;
     while(S[s]==' ') s++;
     while(S[e]==' ') e--;
     for(i=s;i<=e;i++)
     cout<<S[i];
}
int main()
{
    char S[90],c,c1;
    int i=0;
    while(true) {
                c=getchar();
    S[i++]=c;
    if(c=='\n' || c==EOF && c1!='\n')
    {S[i-1]='\0';i=0;display(S);cout<<" is "<<(isGood(S)?"correct.":"incorrect.")<<endl;}
    if(c==EOF) break;
    c1=c;
    }
    return 0;
}
