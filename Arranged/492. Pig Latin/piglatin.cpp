#include<iostream>
#include<string>
using namespace std;
void print(string s1,int j,int i)
{
    int in;char t=0;
    if(s1[j]=='A' || s1[j]=='E' || s1[j]=='I' || s1[j]=='O' || s1[j]=='U' || s1[j]=='a' || s1[j]=='e' || s1[j]=='i' || s1[j]=='o' || s1[j]=='u')
    in=j;
    else {in=j+1;t=s1[j];}
    for(;in<i;in++) cout<<s1[in];
    if(t) cout<<t;
    cout<<"ay";
}
int main()
{
    int i=0,j,l,k;
    char c;
    string s1;
    while((c=getchar())!=EOF) 
           if(isalpha(c)) {while(true) {s1[i++]=c;c=getchar();if(!isalpha(c)) break;}
                           print(s1,0,i); 
                           cout<<c;
                           i=0;}
           else cout<<c; 
    return 0;
}
