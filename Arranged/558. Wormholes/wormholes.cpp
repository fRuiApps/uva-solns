#include<iostream>
#define MAX 1000
#define INF 1<<30
using namespace std;
int amatrix[MAX][MAX];
int main()
{
    int n,m,i,j,k,c,x,y,t,s,ql,min,v,d[MAX];
    bool visited[MAX],inQueue[MAX],possible;
    cin>>c;
    for(i=1;i<=c;i++) {
                       cin>>n>>m;possible=false;
                       for(j=0;j<n;j++) {d[j]=INF;visited[j]=inQueue[j]=false;for(k=0;k<n;k++) amatrix[j][k]=0;}
                       for(j=0;j<m;j++) {cin>>x>>y>>t;amatrix[x][y]=t;}
                       s=0;inQueue[s]=true;ql=1;d[s]=0;
                       while(ql) {
                                  min=INF;
                                  for(j=0;j<n;j++) if(inQueue[j] && d[j]<min) {min=d[j];v=j;}
                                  inQueue[v]=false;ql--;visited[v]=true;
                                  //cout<<v<<endl;
                                  for(j=0;j<n;j++) if(amatrix[v][j]) { 
                                                                      if(visited[j] && d[j]>(d[v]+amatrix[v][j])) possible=true;
                                                                      else {
                                                                            if(d[j]>(d[v]+amatrix[v][j])) {
                                                                                                           if(!inQueue[j])
                                                                                                           {inQueue[j]=true;ql++;}
                                                                                                           d[j]=(d[v]+amatrix[v][j]);
                                                                            }
                                                                      }
                                                   }
                                 }
                       if(possible) cout<<"possible"<<endl; else cout<<"not possible"<<endl;
                      }
    return 0;
}
