#include<iostream>
#include<list>
using namespace std;
int main()
{
    int n,i,j;
    list<int> first(4,100);
    list<int>::iterator it;
    for(it=first.begin();it!=first.end();it++) cout<<*it<<" ";cout<<*it<<" "<<endl;
    for(it=first.end(),it--;it!=first.begin();it--) cout<<*it<<" ";cout<<*it<<" "; //reverse traversal
    cin>>n;
    return 0;
}
