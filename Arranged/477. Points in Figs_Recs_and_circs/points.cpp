#include<iostream>
using namespace std;
int main()
{
    float R[10][4],x,y;
    bool isCirc[10]={false},f;
    int c=0,c1=0,i;
    char t;
    while(true) {
                 cin>>t;
                 if(t=='*') break;
                 if(t=='r') cin>>R[c][0]>>R[c][1]>>R[c][2]>>R[c][3];
                 else {cin>>R[c][0]>>R[c][1]>>R[c][2];isCirc[c]=true;}
                 ++c;
    }
    while(true)
    {
     cin>>x>>y;
     f=0;
     ++c1;
     if(x>9999 && y>9999) break;
     for(i=0;i<c;i++){
     if(!isCirc[i] && x>R[i][0] && x<R[i][2] && y<R[i][1] && y>R[i][3]) 
     {cout<<"Point "<<c1<<" is contained in figure "<<i+1<<endl;f=1;}
     if(isCirc[i] && ((x-R[i][0])*(x-R[i][0])+(y-R[i][1])*(y-R[i][1]))<(R[i][2]*R[i][2]))
     {cout<<"Point "<<c1<<" is contained in figure "<<i+1<<endl;f=1;}}
     if(f==0) cout<<"Point "<<c1<<" is not contained in any figure"<<endl;
    }
    return 0;
}
