#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,f,k,l,Arr[50],i,j;
    bool flag,flg=false;
    while(true)
    {
     cin>>k;l=k-1;flag=true;
     a=0;b=1;c=2;d=3;e=4;f=5;
     if(k==0) break;
     if(!flg) flg=true; else cout<<endl;
     for(i=0;i<=l;i++) cin>>Arr[i];
     while(flag) {
        cout<<Arr[a]<<" "<<Arr[b]<<" "<<Arr[c]<<" "<<Arr[d]<<" "<<Arr[e]<<" "<<Arr[f]<<endl;
        //count++;
        if(f<l) f++;
        else if(e<(l-1)) {e++;f=e+1;}
        else if(d<(l-2)) {d++;e=d+1;f=e+1;}
        else if(c<(l-3)) {c++;d=c+1;e=d+1;f=e+1;}
        else if(b<(l-4)) {b++;c=b+1;d=c+1;e=d+1;f=e+1;}
        else if(a<(l-5)) {a++;b=a+1;c=b+1;d=c+1;e=d+1;f=e+1;}
        else flag=false;
     }
     //cout<<count<<endl;
    }
    return 0;
}
