#include<iostream>
#define rev(a) (a%10)*10+(a/10)
using namespace std;

int W=1;
bool A[55]={false};
int fun(int a)
{
    int t=a%10;
    W=W*10+t;
    A[a]=A[rev(a)]=true;
    //cout<<a<<" "<<W<<endl;
    if((W/100000000)==1) {cout<<W<<endl;A[a]=A[rev(a)]=false;W=W/10;return 1;}
    else if(t==1)
    {
         if(!A[12]) fun(12);
         if(!A[13]) fun(13);
         if(!A[15]) fun(15);
         W=W/10; A[a]=A[rev(a)]=false; return 1;
    }
    else if(t==2)
    {
         if(!A[21]) fun(21);
         if(!A[23]) fun(23);
         if(!A[25]) fun(25);
         W=W/10; A[a]=A[rev(a)]=false; return 1;
    }
    else if(t==3)
    {
         if(!A[31]) fun(31);
         if(!A[32]) fun(32);
         if(!A[34]) fun(34);
         if(!A[35]) fun(35);
         W=W/10; A[a]=A[rev(a)]=false; return 1;
    }
    else if(t==4)
    {
         if(!A[43]) fun(43);
         if(!A[45]) fun(45);
         W=W/10; A[a]=A[rev(a)]=false; return 1;
    }
    else if(t==5)
    {
         if(!A[51]) fun(51);
         if(!A[52]) fun(52);
         if(!A[53]) fun(53);
         if(!A[54]) fun(54);
         W=W/10; A[a]=A[rev(a)]=false; return 1;
    }
}
int main()
{
    fun(12);
    A[12]=false;W=1;
    fun(13);
    A[13]=false;W=1;
    fun(15);
    return 0;
}
