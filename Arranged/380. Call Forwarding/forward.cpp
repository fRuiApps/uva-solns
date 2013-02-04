#include<iostream>
using namespace std;
int A[10000][10000],st,co;
bool hasChanged[10000];
int toNumber(char * s)
{
    int n=0;
    n=n*10+s[0]-'0';n=n*10+s[1]-'0';n=n*10+s[2]-'0';n=n*10+s[3]-'0';
    return n;
}
void print(int n)
{
     cout<<(n/1000)<<((n/100)%10)<<((n/10)%10)<<(n%10);
}
int destination(int time,int source)
{
    //cout<<time<<" "<<source<<" "<<A[source][time]<<" "<<hasChanged[source]<<endl;
    if(!hasChanged[source]) return source;
    if(source==A[source][time]) return source;
    if(source==st) 
    {
     if(co) return 9999; else {co++;return destination(time,A[source][time]);}
    }
    else
    {
     return destination(time,A[source][time]);
    }
}
int main()
{
    int i,j,N,a,b,c,d,source,f,time,fl;
    char s[5];
    cin>>N;
    cout<<"CALL FORWARDING OUTPUT\n";
    for(i=1;i<=N;i++) {
                       for(j=0;j<10000;j++) hasChanged[j]=false;
                       while(1) {
                       fl=0;
                       cin>>s;a=toNumber(s);
                       if(!a) break;
                       if(hasChanged[a]) fl=1;
                       hasChanged[a]=true;
                       cin>>s;b=toNumber(s);cin>>s;c=toNumber(s);cin>>s;d=toNumber(s);
                       //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                       for(j=0;j<10000;j++) if(j>=b && j<=(b+c)) {
                                                                  A[a][j]=((a!=d)?d:9999);
                                                                  //cout<<a<<" "<<j<<" "<<A[a][j]<<endl;
                                                                 }
                                            else if(!fl) A[a][j]=a;
                       }
    cout<<"SYSTEM "<<i<<endl;
    while(1) {
              cin>>s;time=toNumber(s);
              if(time==9000) break;
              cin>>s;source=toNumber(s);
              st=source;co=0;
              f=destination(time,source);
              cout<<"AT ";print(time);cout<<" CALL TO ";print(source);cout<<" RINGS ";print(f);cout<<endl;
             }
    }
    cout<<"END OF OUTPUT\n";
    return 0;
}
