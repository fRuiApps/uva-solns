#include<iostream>
using namespace std;
long gcd(long a,long b) {
if (a%b==0) return b; else return gcd(b,a%b);
}

void Divbygcd(long& a,long& b) {
long g=gcd(a,b);
a/=g;
b/=g;
}

long C(int n,int k){
long numerator=1,denominator=1,toMul,toDiv,i;
if (k>n/2) k=n-k; 
for (i=k;i;i--) {
toMul=n-k+i;
toDiv=i;
Divbygcd(toMul,toDiv); 
Divbygcd(numerator,toDiv);
Divbygcd(toMul,denominator);
numerator*=toMul;
denominator*=toDiv;
}
return numerator/denominator;
}

int main()
{
    int a,b;
    while((cin>>a>>b ) && (a!= 0  && b!=0))
    {
                    cout<<a<<" things taken "<<b<<" at a time is "<<C(a,b)<<" exactly."<<endl;
    }
    return 0;
}
