#include<iostream>
using namespace std;
bool isSlump(char * s,int b,int e)
{
     int i;
     if(s[b]!='D' && s[b]!='E') return 0;
     for(i=(b+1);s[i]=='F' && i<e;i++);
     if(i==(b+1)) return false;
     if(i==e) 
              if(s[i]=='G') return true; else return false;
     else if(isSlump(s,i,e)) return true; else return false;
}
bool isSlimp(char * s,int b,int e)
{
     if(e<=b) return false;
     if(e==b+1 && s[b]=='A' && s[e]=='H') return true;
     else if(s[b]=='A' && s[b+1]=='B' && isSlimp(s,b+2,e-1) && s[e]=='C') return true;
     else if(s[b]=='A' && isSlump(s,b+1,e-1) && s[e]=='C') return true;
     else return false;
}
int main()
{
    char s[70];
    int i,N,l,j;
    bool flag;
    cout<<"SLURPYS OUTPUT\n";
    cin>>N;
    for(i=1;i<=N;i++) {
                       cin>>s;
                       flag=false;
                       l=strlen(s);
                       for(j=1;j<=(l-4);j++) if(isSlimp(s,0,j) && isSlump(s,j+1,l-1)) flag=true;
                       if(flag) cout<<"YES\n"; else cout<<"NO\n";
    }
    cout<<"END OF OUTPUT\n"; 
    return 0;
}
