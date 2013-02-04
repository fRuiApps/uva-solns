#include<iostream>
using namespace std;
bool used[10];
bool isPossible(int pos,int * A,int p)
{
     int i;
     if(pos==3) {
                 for(i=0;i<=4;i++) if(!used[i]&&(((p+A[i])==23)||((p-A[i])==23)||((p*A[i])==23))) return true;
                 return false;
     }
     else {
           for(i=0;i<=4;i++)
           {
            if(!used[i]) {
                          used[i]=true;
                          if(isPossible(pos+1,A,p+A[i])||isPossible(pos+1,A,p-A[i])||isPossible(pos+1,A,p*A[i])) return true;
                          used[i]=false;
            }
           }
     }
     return false;
}
int main()
{
    int A[10],i;
    bool flag=false;
    while(true) {
                 cin>>A[0]>>A[1]>>A[2]>>A[3]>>A[4];
                 for(i=0;i<10;i++) used[i]=false;flag=false;
                 if(A[0]==0) break;
                 for(i=0;i<=4;i++)
                 {
                  if(!used[i]) {
                          used[i]=true;
                          if(isPossible(0,A,A[i])) {flag=true;break;}
                          used[i]=false;
                          }
                 }
                 if(flag) cout<<"Possible\n"; else cout<<"Impossible\n";
    }
    return 0;
}
