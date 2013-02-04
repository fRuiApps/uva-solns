#include<iostream>
#include<string>
using namespace std;
int main()
{
    int D,M,Y,i,L,LR,N,y,LE00,Days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool isLeap;
    long long TD;
    string day_name[]={"Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"};
    string day_name_ago[]={"Wednesday","Tuesday","Monday","Sunday","Saturday","Friday","Thursday"};
    string month_name[]={"","January","February","March","April","May","June","July","August","September","October","November","December"};
    while(true) {
                 cin>>M>>D>>Y;
                 if(D==M && M==Y && D==0) break;
                 if(M<1 || M>12 || D>31 || D<1 || (Y==1752 && M==9 && (D>2 && D<14))) {cout<<M<<"/"<<D<<"/"<<Y<<" is an invalid date.\n";continue;}
                 if(Y>=1753) {
                              isLeap=false;if((Y%100)==0) {if((Y%400)==0) isLeap=true;} else {if((Y%4)==0) isLeap=true;}
                              Days[2]=28+isLeap;
                              if(D>Days[M]) {cout<<M<<"/"<<D<<"/"<<Y<<" is an invalid date.\n";continue;}
                              LR=(Y-1753)/4;N=((Y%100==0)?(Y/100-17-1):(Y/100-17));LE00=(N+1)/4;L=LR-(N-LE00);y=Y-1753;TD=y*365+L;
                              for(i=1;i<M;i++) TD+=Days[i];TD+=D;TD+=108;
                              //cout<<TD<<" "<<L<<endl;
                              cout<<month_name[M]<<" "<<D<<", "<<Y<<" is a "<<day_name[TD%7]<<endl;
                 }
                 else if(Y<=1751) {
                                   isLeap=false;if(Y%4==0) isLeap=true;Days[2]=28+isLeap;
                                   if(D>Days[M]) {cout<<M<<"/"<<D<<"/"<<Y<<" is an invalid date.\n";continue;}
                                   L=(1751-Y)/4;y=1751-Y;TD=y*365+L;
                                   for(i=M+1;i<=12;i++) TD+=Days[i];TD+=(Days[M]-D);TD+=246;
                                   cout<<month_name[M]<<" "<<D<<", "<<Y<<" is a "<<day_name_ago[TD%7]<<endl;
                      }
                 else {
                       Days[2]=29;
                       if(D>Days[M]) {cout<<M<<"/"<<D<<"/"<<Y<<" is an invalid date.\n";continue;}
                       if(M<9) {
                                TD=Days[M]-D;
                                for(i=M+1;i<9;i++) TD+=Days[i];TD+=2;
                                cout<<month_name[M]<<" "<<D<<", "<<Y<<" is a "<<day_name_ago[TD%7]<<endl;
                               }  
                       else if(M>9) {
                                     TD=16;
                                     for(i=10;i<M;i++) TD+=Days[i];TD+=D;
                                     cout<<month_name[M]<<" "<<D<<", "<<Y<<" is a "<<day_name[TD%7]<<endl;
                            }
                       else {
                             if(D<=2) {TD=2-D;cout<<month_name[M]<<" "<<D<<", "<<Y<<" is a "<<day_name_ago[TD%7]<<endl;}
                             else if(D>=14) {TD=D-14;cout<<month_name[M]<<" "<<D<<", "<<Y<<" is a "<<day_name[TD%7]<<endl;}
                            }      
                      }
    }
    return 0;
}
