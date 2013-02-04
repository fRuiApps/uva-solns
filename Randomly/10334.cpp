#include<iostream>
using namespace std;
string add(string ,string);
int main()
{
    int i,n;
    string fibo[1003];
    fibo[0] = "0";fibo[1] = "1";
    for(i = 2;i<=1002;i++)
    fibo[i] = add(fibo[i-1],fibo[i-2]);
    while(cin>>n)
    cout<<fibo[n+2]<<endl;
    return 0;
}

string add(string a,string b)
{
    string sum,temp;
    int i,ans,carry,la,lb,t;
    carry = 0;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    la = a.length();
    lb = b.length();
    if(la>lb)
    {
             temp = a;t = la;
             a = b;la = lb;
             b = temp;lb = t;
    }
    for(i=0;i<la;i++)
    {
            ans = (((a[i] + b[i]) - 2*'0') + carry );
            carry = (ans )/10;
            ans %= 10;ans += '0';
            sum += ans;
    }
    if(la < lb)
    {
    i = la;
    while(i < lb)
    {
          ans = (b[i++]  + carry  - '0');
          carry = ans/10;
          ans %= 10;ans += '0';
          sum += ans;
    }
    }
    carry += '0';
    if(carry != '0')
    sum += carry;
    reverse(sum.begin(),sum.end());
    return sum;
    
}
    

