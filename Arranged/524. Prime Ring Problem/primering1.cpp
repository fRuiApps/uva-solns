#include<iostream>
using namespace std;
bool isPrime[41]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0};
bool used[20];
int j,list[20];
void print()
{
     int k;
     for(k=0;k<=j;k++) cout<<list[k]<<" ";cout<<endl;
}
bool isPossible(int st,int n,int N)
{
     bool a=false;int k;
     if(n==1) {
               if(isPrime[st+list[j]] && isPrime[st+1])
               {
                for(k=0;k<=j;k++) cout<<list[k]<<" ";cout<<st<<endl;
                return true;
               }
               else return false;
     }
     else {
           if(!isPrime[st+list[j]]) return false;
           used[st]=true;list[++j]=st;
           print();
           for(k=2;k<=N;k++) if(!used[k]) a = a||isPossible(k,n-1,N);
           used[st]=false;j--;
           return a;
     }
}
int main()
{ 
    int i,k,l,N;
    while(cin>>N) {
                   list[0]=1;j=0;
                   if(N==1) cout<<1<endl; 
                   else {
                         for(i=2;i<=N;i++) used[i]=false;used[1]=true;
                         for(i=2;i<=N;i++) isPossible(i,N-1,N);
                   }
    }
    return 0;
}
