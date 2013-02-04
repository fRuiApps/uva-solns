#include<iostream>
#include<vector>
using namespace std;
vector<int> tree,LEVEL,LEFT,RIGHT;
int lastOcc(int index,int level)
{
    LEVEL[index]=level;
    if(tree[index]==-1) return index; else return lastOcc(lastOcc(index+1,level-1)+1,level+1);
}
int main()
{
    int i,j,k,c=1,sl,er,a,neg,pos;
    bool flag;
    while(cin>>k) tree.push_back(k);
    j=0;LEVEL.resize(tree.size());
    while(true) {
                 a=lastOcc(j,0);if(a==j) break;
                 LEFT.clear();LEFT.resize(100);RIGHT.clear();RIGHT.resize(100);
                 for(i=j;i<=a;i++) if(tree[i]>=0) {
                                                      if(LEVEL[i]<0) 
                                                                        LEFT[-LEVEL[i]]+=tree[i];
                                                      else
                                                                        RIGHT[LEVEL[i]]+=tree[i];
                 }
                 j=a+1;sl=er=0;flag=false;
                 for(i=1;LEFT[i];i++,sl++);for(i=0;RIGHT[i];i++,er++);
                 cout<<"Case "<<c<<":"<<endl; 
                 for(i=sl;i>=1;i--) {if(flag) cout<<" "; else flag=true; cout<<LEFT[i];}
                 for(i=0;i<er;i++) {if(flag) cout<<" "; else flag=true;cout<<RIGHT[i];}
                 cout<<endl<<endl;
                 c++;
                }
    return 0;
}
