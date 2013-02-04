#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<map>
using namespace std;

#define square(x) x*x
#define MAX(a,b) ((a>b)?(a):(b))
#define ABS(a)	   (((a) < 0) ? -(a) : (a))
#define MIN(a,b) ((a<b)?(a):(b))
#define INF 1<<25
#define PIE acos(-1)
#define FOR(i,s,e) for(i=s;i<=e;i++)
#define not_zero() long n; while(cin>>n && n != 0)
#define NTC int ntc;cin>>ntc;while(ntc--) 
#define VLL vector<long long>

#define big  2000000000
typedef unsigned long long ull;
typedef long double ld;

long long power(long long,long long);
int main()
{
    long long two = 30,three = 20,five = 14,seven = 12,arr[6000] = {0};
    long long  pro = 1,i,j,k,l,cnt = 1;
    //VLL v;
    
    FOR(i,0,two)
    {
       FOR(j,0,three)
       {
          FOR(k,0,five)
          {
               FOR(l,0,seven)
               {
                            
                  pro = power(7,l)*power(3,j)*power(5,k)*power(2,i);           
                  if(pro>0  && pro<= big)              
                   {arr[cnt++] = pro; }
               }
           }
       }
    }
    sort(arr,arr+cnt);
      
    long chk,chk2;
    not_zero()
    {
        chk = n%10;
        chk2 = n%100;
        if(chk == 1 && chk2 != 11) cout<<"The "<<n<<"st humble number is "<<arr[n]<<".\n";
        else if(chk == 2 && chk2 != 12) cout<<"The "<<n<<"nd humble number is "<<arr[n]<<".\n";
        else if(chk == 3 && chk2 != 13) cout<<"The "<<n<<"rd humble number is "<<arr[n]<<".\n";
        else   cout<<"The "<<n<<"th humble number is "<<arr[n]<<".\n";

    } 
    return 0;
}
long long power(long long a,long long b)
{
      long long ans;
      if(b == 0) return 1;
      else 
      if(b == 1) return a;
      else 
      if(b%2==0) 
      {
                 ans =  power(a,b/2);
                 return ans*ans;
      }
      else 
      return a*power(a,b-1);
}
           
      
        
