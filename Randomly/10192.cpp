#include<stdio.h>
#include<string.h>
#include<iostream.h>
# define maxi 1005
#define max(a,b) (a<b?b:a)
char s1[maxi],s2[maxi]; 
int M,N,i,j,cnt = 1, m[maxi][maxi],k,l; 
int main()
{    
     while(gets(s1)&& s1[0] != '#')
    {   
       gets(s2);         
       M = strlen(s1);N = strlen(s2);         
       for(i=1; i<=M; i++)
       for(j=1; j<=N; j++)
       {
                if(s1[i-1]==s2[j-1]) m[i][j] = 1+m[i-1][j-1];
                else m[i][j] = max(m[i][j-1], m[i-1][j]);
                
                for(k = 1;j<=M;k++) 
                {for(l = 1;l<=N;l++) cout<<m[k][l]<<"\t";cout<<endl;}
                
       }
       printf("Case #%d: you can visit at most %d cities.\n",cnt++,m[M][N]); 
    }
       return 0;
}
       
