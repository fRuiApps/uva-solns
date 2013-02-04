#include<iostream>
using namespace std;
int main()
{
    int N,N1,N2,N3,N4;
    while(cin>>N) {
    N1=(N<<24);
    N2=(((N>>8)<<24)>>8);if(N2<0) N2^=-16777216;
    N3=(((N>>16)<<24)>>16);if(N3<0) N3^=-65536;
    N4=(N>>24);if(N4<0) N4^=-256;
    cout<<N<<" converts to "<<(N1+N2+N3+N4)<<endl;
    }
    return 0;
}
