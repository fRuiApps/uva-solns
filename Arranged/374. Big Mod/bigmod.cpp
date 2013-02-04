#include<iostream>
using namespace std;
int ref[1000000];
unsigned int result(unsigned int B,unsigned int P,unsigned int M)
{
    //cout<<B<<" "<<P<<endl;
    if(P<1000000) {
                        if(ref[P]==-1) {
                        if(B==0) ref[P]=0;
                        else if(P==0) {if(M==1) ref[P]=0; else ref[P]=1;}
                        else if(P==1)  ref[P]=(B%M);
                        else ref[P]=(result(B,P/2,M)*result(B,P-P/2,M))%M;
                        }
                        return ref[P];
                       }
    else return (result(B,P/2,M)*result(B,P-P/2,M))%M;
}    
int main()
{
    unsigned int B,P,M,i,j;
    while(cin>>B>>P>>M) {
                         for(i=0;i<1000000;i++) ref[i]=-1;
                         cout<<result(B,P,M)<<endl;
    }
    return 0;
}
