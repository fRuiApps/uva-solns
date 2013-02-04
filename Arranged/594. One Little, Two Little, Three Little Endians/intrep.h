#include<iostream>
using namespace std;
#ifndef intrep_h
#define intrep_h
void represent(int N)
{
     int s[32]={0},i=0,sg,j,c=1,temp;
     sg=(N<0)?-1:1;
     if(N<0) N=-N;
     while(N) {s[i++]=N%2;N/=2;}
     if(sg==-1)
     {
      for(j=0;j<32;j++) {if(s[j]==0) s[j]=1; else s[j]=0;}
      for(j=0;j<32;j++) {temp=s[j]+c;s[j]=temp%2; c=temp/2;}
     }
     for(i=31;i>=0;i--)
     {cout<<s[i];
     if((i%8)==0) cout<<" ";}
     cout<<endl;
}
#endif
