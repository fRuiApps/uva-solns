#include<iostream>
using namespace std;
int main()
{
    int m,n,t,i,j,a,b,c,d,maxburgers[10100],minbeer[10100];
    while(cin>>m>>n>>t) {
                         maxburgers[0]=minbeer[0]=0;
                         for(i=1;i<=t;i++) {
                                            if((i-m)>=0) {
                                                          a=1+maxburgers[i-m];
                                                          b=minbeer[i-m];
                                                         }
                                            else         {
                                                          a=maxburgers[i-1];
                                                          b=minbeer[i-1]+1;
                                                         }
                                            if((i-n)>=0) {
                                                          c=1+maxburgers[i-n];
                                                          d=minbeer[i-n];
                                                         }
                                            else         {
                                                          c=maxburgers[i-1];
                                                          d=minbeer[i-1]+1;
                                                         }
                                            if(b<d) {maxburgers[i]=a;minbeer[i]=b;}
                                            else if(b==d) {if(a>c) {maxburgers[i]=a;minbeer[i]=b;} else {maxburgers[i]=c;minbeer[i]=d;}}
                                            else {maxburgers[i]=c;minbeer[i]=d;}
                                           }
                         cout<<maxburgers[t];if(minbeer[t]) cout<<" "<<minbeer[t];cout<<endl;
                         }
    return 0;
}
