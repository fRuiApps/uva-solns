#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
int main()
{
    bool map[26][26],used[26];
    int i,j,m,k,curr,bw,bwnet,bwf,pos[26],l;
    char order[9],orderf[9];
    string input;
    while(true) {
                 cin>>input;if(input=="#") break;
                 for(i=0;i<26;i++) {used[i]=false;pos[i]=0;for(j=0;j<26;j++) map[i][j]=false;}
                 l=input.length();
                 for(i=0;i<l;i++) {
                                   curr=input[i]-'A';used[curr]=true;
                                   for(i=i+2;input[i]!=';'&&input[i]!=0;i++) {map[curr][input[i]-'A']=map[input[i]-'A'][curr]=used[input[i]-'A']=true;}
                                  }
                 m=0;
                 for(i=0;i<26;i++) if(used[i]) order[m++]=i+'A';
                 order[m]='\0';bwf=10;
                 do{
                    bwnet=0;
                    for(i=0;i<m;i++) pos[order[i]-'A']=i;
                    for(j=0;j<26;j++)
                    {
                     bw=0;
                     if(!used[j]) continue;
                     for(k=0;k<26;k++) if(map[j][k] && (int)fabs(pos[k]-pos[j])>bw) bw=(int)fabs(pos[k]-pos[j]);
                     if(bw>bwnet) bwnet=bw;
                    }
                    if(bwf>bwnet) {bwf=bwnet;strcpy(orderf,order);}
                   }while(next_permutation(order,order+m));
                 for(i=0;i<m;i++) cout<<orderf[i]<<" ";cout<<"-> "<<bwf<<endl;
    }
    return 0;
}
