#include<iostream>
using namespace std;
int main()
{
    char index[10000][20],c,forder[27]={0};
    bool used[27]={false},order[27][27]={false};
    int i=0,j=0,k,i1,j1,nbefore[27]={0},oi=0;
    while(true) {
                 c=getchar();if(c=='#') break;
                 if(c=='\n') {index[i][j]='\0';i++;j=0;}
                 else {index[i][j++]=c;used[c-'A']=true;}
                }
    for(i1=0;i1<i-1;i1++) {
                           for(j1=i1+1;j1<i;j1++) {
                                                   k=0;
                                                   while(index[i1][k]==index[j1][k]) k++;
                                                   if(index[i1][k]=='\0' || index[j1][k]=='\0') continue;
                                                   order[index[j1][k]-'A'][index[i1][k]-'A']=true;
                                                  }
                          }
    for(i1=0;i1<27;i1++) {
                          if(!used[i1]) continue;
                          for(j1=0;j1<27;j1++) if(order[i1][j1]) for(k=0;k<27;k++) if(order[j1][k]) order[i1][k]=true;
                         }
    for(i1=0;i1<27;i1++) {
                          if(!used[i1]) continue;
                          for(j1=0;j1<27;j1++) if(order[i1][j1]) nbefore[i1]++;
                         }
    for(i1=0;i1<27;i1++) if(used[i1]) forder[nbefore[i1]]=i1+'A';
    cout<<forder<<endl;
    return 0;
}
