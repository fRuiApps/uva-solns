#include<iostream>
#include<iomanip>
#include<math.h>
#define MAX 20000
using namespace std;
char field[MAX][MAX],ref[MAX][MAX];
void flood_fill(char c,int i,int j,int &m,int &n,int r)
{
    ref[i][j]=r;
    if((j+1)<n && field[i][j+1]==c && ref[i][j+1]==0) flood_fill(c,i,j+1,m,n,r);
    if((j-1)>=0 && field[i][j-1]==c && ref[i][j-1]==0) flood_fill(c,i,j-1,m,n,r);
    if((i-1)>=0 && field[i-1][j]==c && ref[i-1][j]==0) flood_fill(c,i-1,j,m,n,r);
    if((i+1)<m && field[i+1][j]==c && ref[i+1][j]==0) flood_fill(c,i+1,j,m,n,r);
    if((i-1)>=0 && (j-1)>=0 && field[i-1][j-1]==c && ref[i-1][j-1]==0) flood_fill(c,i-1,j-1,m,n,r);
    if((i+1)<m && (j+1)<n && field[i+1][j+1]==c && ref[i+1][j+1]==0) flood_fill(c,i+1,j+1,m,n,r);
    if((i-1)>=0 && (j+1)<n && field[i-1][j+1]==c && ref[i-1][j+1]==0) flood_fill(c,i-1,j+1,m,n,r);
    if((i+1)<m && (j-1)>=0 && field[i+1][j-1]==c && ref[i+1][j-1]==0) flood_fill(c,i+1,j-1,m,n,r);
}
void operate(char field[][MAX],int &m,int &n)
{
     char width[MAX]={0};
     int i,j,f=0;
     for(i=0;i<m;i++) for(j=0;j<n;j++) ref[i][j]=0;
     for(i=0;i<m;i++) for(j=0;j<n;j++) {
                                        if(ref[i][j]==0)  {f++;flood_fill(field[i][j],i,j,m,n,f);}
                                        if(width[j]<ref[i][j]) width[j]=ref[i][j];
     }
     width[0]=1;
     for(i=1;i<n;i++) width[i]=(log10(width[i])+2);
     for(i=0;i<m;i++) {for(j=0;j<n;j++) cout<<setw(width[j])<<(int)ref[i][j];cout<<endl;}
}    
int main()
{
    char c,c1;
    int i,j,l,k;
    bool done;
    while(true)
    {
     i=j=0;
     done=false;
     l=-1;
     while(!done)
     {
      c=getchar();
      if(c=='\n') {field[i][j]='\0';l=j;j=0;i++;}
      else if(c=='%') {done=true;while((c=getchar())!='\n');continue;}
      else if(c==' ') {}
      else if(c==EOF) {done=true;if(j==l || l==-1) {field[i][j]='\0';i++;l=j;}continue;}
      else {field[i][j]=c;j++;}
     }
     operate(field,i,l);
     cout<<"%"<<endl;
     if(c==EOF) break;
    }
    return 0;
}
