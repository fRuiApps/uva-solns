#include<iostream>
#include<sstream>
#include<queue>
#define MAX 210
#define INF 1<<25
using namespace std;
bool pathExists(string s1,string s2)
{
     int i,n=0;
     for(i=0;s1[i]&&s2[i];i++) {if(s1[i]!=s2[i]) n++;if(n>1) return false;}
     if(s1[i]==s2[i]) return true;
     return false;
}
int shortestPath(int adjMat[][MAX],int n,int v1,int v2)
{
    int color[MAX]={0},i,j,u,plength[MAX];queue<int> Q;
    if(adjMat[v1][v2]) return 1;
    color[v1]=1;Q.push(v1);plength[v1]=0;
    while(!Q.empty()) {
          u=Q.front();Q.pop();
          for(i=0;i<n;i++) if(adjMat[u][i] && color[i]==0) {color[i]=1;plength[i]=plength[u]+1;Q.push(i);}
          color[u]=2;
    }
    return plength[v2];
}
int main()
{
    int N,i,j,k,n,i1,i2,p,path[MAX][MAX];
    bool f=false;
    string w,w1,w2,words[MAX],str;
    cin>>N;
    getline(cin,w);getline(cin,w);
    for(i=1;i<=N;i++)
           {
              n=0;
              if(f) cout<<endl; else f=true;
              while(true) {
                getline(cin,w);
                if(w=="*") break;
                words[n++]=w;
              }
              for(j=0;j<n;j++) for(k=0;k<n;k++) if(pathExists(words[j],words[k])) path[j][k]=1; else path[j][k]=0;
              while(getline(cin,str)) {
                 if(str[0]=='\0') break;
                 stringstream in(str);
                 in>>w1>>w2;for(j=0;j<n;j++) if(w1==words[j]) i1=j; else if(w2==words[j]) i2=j;
                 p=shortestPath(path,n,i1,i2);
                 cout<<w1<<" "<<w2<<" "<<p<<endl;
              }
           }
    return 0;
}
