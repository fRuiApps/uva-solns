#include<iostream>
#include<string.h>
using namespace std;
void associate(char * X)
{
    char s[10000];s[0]=0;
    strcpy(s,X);
    strcat(X,"2");
    strcat(X,s);
}
void production(char * X)
{
     int i;
     for(i=0;X[i]!='\0';i++) if(X[i]=='0') {strcat(X,"N");return;}
     if(X[0]=='2' && X[1]) {for(i=0;X[i]!='\0';i++) X[i]=X[i+1];return;}
     else if(X[0]=='3') {for(i=0;X[i]!='\0';i++) X[i]=X[i+1];production(X);associate(X);return;}
     else {strcat(X,"N");return;}
}
int main()
{
    char X[10000];
    int i;
    bool flag;
    while(true) {
                 cin>>X;flag=true;
                 if(X[0]=='0' && X[1]==0) break;
                 production(X);
                 for(i=0;X[i]!='\0';i++) if(!(X[i]>='0' && X[i]<='9')) {flag=false;break;}
                 if(flag) cout<<X<<endl; else cout<<"NOT ACCEPTABLE\n";
    }
    return 0;
}
