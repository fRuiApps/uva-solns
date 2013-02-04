#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int noWords(char s[])
{
 int i,l,n=0;
 l=strlen(s);
 for(i=1;i<=l;i++)
 if((s[i]==' ' || s[i]=='\0')&&s[i-1]!=' ') n++;
 return n;
}
int main()
{
    int regions[25][4],icons[51][2],dist2[51],i=1,r=0,j,ck=0,x,y,z=0,M;
    char t,c,s[10000000];
    while((c=getchar())!='#')
    {
     s[z++]=c;
     if(c=='\n') {s[z-1]='\0';z=0;} else continue;
     if(noWords(s)==5) 
     {sscanf(s,"%c %d %d %d %d",&c,&regions[r][0],&regions[r][1],&regions[r][2],&regions[r][3]);r++;}
     else if(noWords(s)==3)
     {sscanf(s,"%c %d %d",&c,&x,&y);
     if(c=='I') {icons[i][0]=x;icons[i][1]=y;i++;}
     else
     {
      t='\0';
      for(j=0;j<r;j++) 
      if(x>=regions[j][0] && x<=regions[j][2] && y>=regions[j][1] && y<=regions[j][3]) t=j+'A';
      if(t) printf("%c\n",t);
      else { M=600000;
            for(j=1;j<i;j++) {
                dist2[j]=(icons[j][0]-x)*(icons[j][0]-x) + (icons[j][1]-y)*(icons[j][1]-y);
                if(M>dist2[j]) M=dist2[j]; }
            for(j=1;j<i;j++) if(dist2[j]==M) printf("%3d",j); printf("\n");
           }
      }
      }
    }
    return 0;
}
