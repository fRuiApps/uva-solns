#include<iostream>
#define MAX 30
using namespace std;
void flood_fill(char field[][MAX],char ref[][MAX],int i,int j,int &m,int &n)
{
    ref[i][j]=1;
    if((j+1)<n && field[i][j+1]=='1' && ref[i][j+1]==0) flood_fill(field,ref,i,j+1,m,n);
    if((j-1)>=0 && field[i][j-1]=='1' && ref[i][j-1]==0) flood_fill(field,ref,i,j-1,m,n);
    if((i-1)>=0 && field[i-1][j]=='1' && ref[i-1][j]==0) flood_fill(field,ref,i-1,j,m,n);
    if((i+1)<m && field[i+1][j]=='1' && ref[i+1][j]==0) flood_fill(field,ref,i+1,j,m,n);
    if((i-1)>=0 && (j-1)>=0 && field[i-1][j-1]=='1' && ref[i-1][j-1]==0) flood_fill(field,ref,i-1,j-1,m,n);
    if((i+1)<m && (j+1)<n && field[i+1][j+1]=='1' && ref[i+1][j+1]==0) flood_fill(field,ref,i+1,j+1,m,n);
    if((i-1)>=0 && (j+1)<n && field[i-1][j+1]=='1' && ref[i-1][j+1]==0) flood_fill(field,ref,i-1,j+1,m,n);
    if((i+1)<m && (j-1)>=0 && field[i+1][j-1]=='1' && ref[i+1][j-1]==0) flood_fill(field,ref,i+1,j-1,m,n);
}
int main()
{
    int size,i,j,num,c=0;
    char field[MAX][MAX],ref[MAX][MAX];
    while(cin>>size)
    {
     num=0;c++;
     for(i=0;i<size;i++) {cin>>field[i];for(j=0;j<size;j++) ref[i][j]=0;}
     for(i=0;i<size;i++) for(j=0;j<size;j++) if(field[i][j]=='1' && ref[i][j]==0) {num++;flood_fill(field,ref,i,j,size,size);}
     cout<<"Image number "<<c<<" contains "<<num<<" war eagles.\n";
    }
    return 0;
}
