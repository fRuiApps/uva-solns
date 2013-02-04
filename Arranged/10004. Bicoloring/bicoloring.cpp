#include<iostream>
#include<queue>
#include<list>
using namespace std;
bool isPossible(list<int> alist[],int n,char * col)
{
     int i;
     char c;
     list<int>::iterator it;
     for(i=0;i<n;i++) {
                       c=col[i];
                       for(it=alist[i].begin();it!=alist[i].end();++it) if(col[*it]==c) return false;
     }
     return true;
}
int main()
{
    int n,e,i,a,b,s=0,u,v;
    char color[200],col[200],c;
    list<int>::iterator it;
    queue<int> Q;
    while(true) {
                 cin>>n;if(n==0) break;cin>>e;s=0;c='b';
                 list<int> alist[200];
                 for(i=0;i<e;i++) {cin>>a>>b;alist[a].push_back(b);alist[b].push_back(a);}
                 for(i=0;i<n;i++) color[i]=col[i]='w';
                 color[s]='g';
                 Q.push(s);
                 while(!Q.empty()) {
                                    u=Q.front();
                                    Q.pop();
                                    if(col[u]=='w') c='b'; else c='w';
                                    for(it=alist[u].begin();it!=alist[u].end();++it) {
                                                                                    v=*it;
                                                                                    if(color[v]=='w') {
                                                                                                       color[v]='g';
                                                                                                       col[v]=c;
                                                                                                       Q.push(v);
                                                                                    }
                                    }
                                    color[u]='b';
                 }
                 if(isPossible(alist,n,col)) cout<<"BICOLORABLE.\n"; else cout<<"NOT BICOLORABLE.\n";
    }
    return 0;
}
