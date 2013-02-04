#include<iostream>
using namespace std;
#define max 1<<30
int main()
{
long long b1,b2,b3,c1,c2,c3,g1,g2,g3,min,i;
string ans[7] = {"BCG","BGC","CBG","CGB","GBC","GCB"};
while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3)
{
long long s[7] = {0};
string pri = "ZZZZ";
min = max;

s[1] = b2+b3+c1+c3+g1+g2; if(min>s[1]) min = s[1];
s[2] = b2+b3+g1+g3+c1+c2; if(min>s[2]) min = s[2];
s[3] = c2+c3+b1+b3+g1+g2; if(min>s[3]) min = s[3];
s[4] = c2+c3+g1+g3+b1+b2; if(min>s[4]) min = s[4];
s[5] = g2+g3+b1+b3+c1+c2; if(min>s[5]) min = s[5];
s[6] = g2+g3+c1+c3+b1+b2; if(min>s[6]) min = s[6];
for(i =1;i<7;i++)
{
if(s[i] == min)
if(ans[i-1]<pri) pri = ans[i-1];
}

cout<<pri<<" "<<min<<endl;
}
return 0;
}
