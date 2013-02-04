#include<iostream>
#define MAX 101
using namespace std;
void flood_fill(char field[][MAX],char ref[][MAX],int i,int j,int &m,int &n)
{
    ref[i][j]=1;
    if((j+1)<n && field[i][j+1]=='@' && ref[i][j+1]==0) flood_fill(field,ref,i,j+1,m,n);
    if((j-1)>=0 && field[i][j-1]=='@' && ref[i][j-1]==0) flood_fill(field,ref,i,j-1,m,n);
    if((i-1)>=0 && field[i-1][j]=='@' && ref[i-1][j]==0) flood_fill(field,ref,i-1,j,m,n);
    if((i+1)<m && field[i+1][j]=='@' && ref[i+1][j]==0) flood_fill(field,ref,i+1,j,m,n);
    if((i-1)>=0 && (j-1)>=0 && field[i-1][j-1]=='@' && ref[i-1][j-1]==0) flood_fill(field,ref,i-1,j-1,m,n);
    if((i+1)<m && (j+1)<n && field[i+1][j+1]=='@' && ref[i+1][j+1]==0) flood_fill(field,ref,i+1,j+1,m,n);
    if((i-1)>=0 && (j+1)<n && field[i-1][j+1]=='@' && ref[i-1][j+1]==0) flood_fill(field,ref,i-1,j+1,m,n);
    if((i+1)<m && (j-1)>=0 && field[i+1][j-1]=='@' && ref[i+1][j-1]==0) flood_fill(field,ref,i+1,j-1,m,n);
}
int main()
{
    int m,n,i,j,num;
    char field[MAX][MAX],ref[MAX][MAX];
    while(true)
    {
     num=0;
     cin>>m>>n;
     if(m==0) break;
     for(i=0;i<m;i++) for(j=0;j<n;j++) {cin>>field[i][j];ref[i][j]=0;}
     for(i=0;i<m;i++) for(j=0;j<n;j++) if(field[i][j]=='@' && ref[i][j]==0) {num++;flood_fill(field,ref,i,j,m,n);}
     cout<<num<<endl;
    }
    return 0;
}
