#include<stdio.h>
#define max(a,b) (a<b?b:a)
int main()
{
    int h1,h2,i,j,cnt = 1;
    while(scanf("%d%d",&h1,&h2)&&(h1||h2))
    {
       int m[105][105] = {0},s1[105] = {0},s2[105] = {0};               
       for(i=0;i<h1;i++) scanf("%d",&s1[i]); 
       for(i=0;i<h2;i++) scanf("%d",&s2[i]); 
       //printf("inputs taken\n");
       for(i=1; i<=h1; i++)
       for(j=1; j<=h2; j++)
       {
                 if(s1[i-1]==s2[j-1]) m[i][j] = 1+m[i-1][j-1];
                 else m[i][j] = max(m[i][j-1], m[i-1][j]);
       }
       printf("Twin Towers #%d\n",cnt++);
       printf("Number of Tiles : %d\n\n",m[h1][h2]); 
    }
    return 0;
}
