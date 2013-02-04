#include<iostream>
#include<vector>
#define INF 1<<25
using namespace std;
int main()
{
    int cost[11][11][1001]={0},val[11][1001],d,n,k,i,j,i1,j1,c,s=1; 
    while(true) 
    {
     cin>>n>>k;
     if(n==0) break;
     for(i=0;i<n;i++) {
                       for(j=0;j<n;j++) {
                                         if(j!=i) {
                                                   cin>>d;
                                                   for(i1=0;i1<d;i1++)   {
                                                                          cin>>c;
                                                                          for(j1=i1;j1<k;j1+=d) cost[i][j][j1]=c;
                                                                         }
                                                  }
                                        }
                       }
     //for(i=0;i<n;i++) for(j=0;j<n;j++) {cout<<"("<<i<<","<<j<<")\n";for(i1=0;i1<k;i1++) cout<<cost[i][j][i1]<<" ";cout<<endl;}
     for(i=0;i<n;i++) for(j=0;j<k;j++) val[i][j]=INF;
     for(i=0;i<n;i++) val[i][0]=(cost[0][i][0]?cost[0][i][0]:INF);
     for(i=0;i<k-1;i++) {
                         for(j=0;j<n;j++) {
                                           if(val[j][i]==INF) continue;
                                           for(i1=0;i1<n;i1++) if(cost[j][i1][i+1] && val[j][i]+cost[j][i1][i+1]<val[i1][i+1]) val[i1][i+1]=val[j][i]+cost[j][i1][i+1];
                                          }
                        }
     cout<<"Scenario #"<<s<<"\n";
     if(val[n-1][k-1]==INF) cout<<"No flight possible.\n\n"; else cout<<"The best flight costs "<<val[n-1][k-1]<<"."<<endl<<endl;
     s++;
    }
    return 0;
}
