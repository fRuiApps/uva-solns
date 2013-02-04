#include<iostream>
using namespace std;
int main()
{
    int i,y1,y2,n,n1;
    while(cin>>y1>>y2) {
                        n=n1=0;
                        for(i=y1;i<=y2;i++) {if((i%4==0 && i%100!=0)||(i%400==0)) n++;if(i%4==0) n1++;}
                        cout<<n<<" "<<n1<<endl;
                       }
    return 0;
}
