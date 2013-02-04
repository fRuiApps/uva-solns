#include<iostream>
#include<stdio.h>
using namespace std;
void turn(int &i,int &j,int f)
{
     if(i==1 && j==0) {i=0;j=-1*f;}
     else if(i==-1 && j==0) {i=0;j=1*f;}
     else if(i==0 && j==1) {i=1*f;j=0;}
     else if(i==0 && j==-1) {i=-1*f;j=0;}
}
int main()
{
    char maze[1000][1000],visited[1000][1000],c;
    int b,w,i,j,x,y,v[5];
    while(true)
    {
     cin>>b>>w; if(b==0) break;
     for(i=0;i<=(b+1);i++) maze[i][0]='1';
     for(i=1;i<=(w+1);i++) maze[0][i]=maze[b+1][i]='1';
     for(i=1;i<=b;i++) {cin>>(maze[i]+1);maze[i][w+1]='1';maze[i][w+2]=0;}
     for(i=1;i<=b;i++) for(j=1;j<=w;j++) {visited[i][j]=0;if(maze[i][j]=='1') visited[i][j]=5;}
     for(i=0;i<5;i++) v[i]=0;
     //for(i=0;i<=(b+1);i++){for(j=0;j<=(w+1);j++) cout<<maze[i][j]<<" ";cout<<endl;}
     y=b;x=1;i=1;j=0;
     while(true)
     {
      if(!((i==1 && j==0 && maze[y+1][x]=='1')||(i==-1 && j==0 && maze[y-1][x]=='1')||(i==0 && j==1 && maze[y][x-1]=='1')||(i==0 && j==-1 && maze[y][x+1]=='1')))
      {turn(i,j,-1);x+=i;y+=j; (visited[y][x])++;}
      else if(maze[y+j][x+i]=='1') turn(i,j,1);
      else {x+=i;y+=j; (visited[y][x])++;}
      if(x==1 && y==b) break;
     }
     for(i=1;i<=b;i++) for(j=1;j<=w;j++) v[visited[i][j]]++;
     printf("%3d%3d%3d%3d%3d\n",v[0],v[1],v[2],v[3],v[4]);
    }
    return 0;
}
