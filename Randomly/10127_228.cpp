#include<iostream>
using namespace std;
int main()
{
    int base,rem10,remprev10,remcrnt10,remcrnt11,i = 2;
    while(cin>>base)
    {
                    remcrnt11 = 11%base;
                    rem10 = 10%base;
                    remprev10 = rem10;
                    while(remcrnt11 != 0)
                    {
                                    i++;
                                    remcrnt10 = (remprev10*rem10)%base; 
                                    remprev10 = remcrnt10;
                                    remcrnt11 = (remcrnt10 + remcrnt11)%base;
                    }      
    cout<<i<<endl;
    i = 2;
    }
    return 0;
}
