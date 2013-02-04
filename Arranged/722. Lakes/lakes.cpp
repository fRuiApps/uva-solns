#include<iostream>
using namespace std;
int lake;
void flood_fill(char field[][105],char ref[][105],int i,int j)
{
    if(field[i][j]=='0') {ref[i][j]=1;lake++;
    if(ref[i][j+1]==0) flood_fill(field,ref,i,j+1);
    if(ref[i][j-1]==0) flood_fill(field,ref,i,j-1);
    if(ref[i-1][j]==0) flood_fill(field,ref,i-1,j);
    if(ref[i+1][j]==0) flood_fill(field,ref,i+1,j);
    if(ref[i-1][j-1]==0) flood_fill(field,ref,i-1,j-1);
    if(ref[i+1][j+1]==0) flood_fill(field,ref,i+1,j+1);
    if(ref[i-1][j+1]==0) flood_fill(field,ref,i-1,j+1);
    if(ref[i+1][j-1]==0) flood_fill(field,ref,i+1,j-1);}
}
int main()
{
    int N,i,j,k,l,ml,r,c1,i1,j1;
    char s[105],area[105][105],c,ref[105][105];
    bool flag=true;
    cin>>N;
    while((c=getchar())!='\n');
    c=getchar();
    for(i=1;i<=N;i++)
    {
     cin>>r>>c1;j=1;l=ml=0;
     while((c=getchar())!='\n');
     while(true) {
     l=0;
     while(true) {c=getchar(); if(c=='\n' || c==EOF) break; s[l++]=c;}
     s[l]='\0';if(!ml) ml=l;
     if(l==0) break;
     for(k=1;s[k-1]!='\0';k++) area[j][k]=s[k-1];
     j++;
     }
     c=getchar();
     lake=0;
     for(i1=0;i1<105;i1++) for(j1=0;j1<105;j1++) ref[i1][j1]=0;
     for(k=0;k<=(ml+1);k++) area[0][k]=area[j][k]='1';
     for(k=0;k<=j;k++) {area[k][0]=area[k][ml+1]='1';area[k][ml+2]='\0';}
     //for(i1=0;i1<=j;i1++) {for(j1=0;j1<=(ml+1);j1++) cout<<area[i1][j1];cout<<endl;}
     flood_fill(area,ref,r,c1);
     //cout<<r<<" "<<c1<<" "<<area[r][c1]<<endl;
     //for(i1=0;i1<=j;i1++) {for(j1=0;j1<=(ml+1);j1++) cout<<(int)ref[i1][j1];cout<<endl;}
     if(flag) flag=0; else cout<<endl;
     cout<<lake<<endl;
    }
    return 0;
}
