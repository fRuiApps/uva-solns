#include<iostream>
using namespace std;
long bigmod(long,long,long);
int main()
{
    long base,index,remnum,result;
    cin>>base>>index>>remnum;
    result = bigmod( base, index , remnum);
    cout<<"\n\n result "<<result;
    return 0;
}

long bigmod(long base,long index,long remnum)
{
     
     long res,ret;
     if(index == 0) {ret = 1;
     return ret;}
     
     else if((index%2) == 0)
     {
          res = bigmod( base, (index/2), remnum);
          ret =  (res*res) %remnum;
          return ret;
     }
     
     else
     {
         ret =  ((base%remnum)*bigmod((long) base ,(long) index - 1,(long)remnum))%remnum;
         //cout<<"\n index "<<index<<"returning "<<ret;
         return ret;
     }
}
