#include<stdio.h>
#include<string.h>
# define maxi 1005
#define max(a,b) (a<b?b:a)
char s1[maxi],s2[maxi]; 
int M,N,i,j, m[maxi][maxi]; 
int main()
{    
     while(gets(s1))
    {   
       gets(s2);         
       M = strlen(s1);N = strlen(s2);         
       for(i=1; i<=M; i++)
       for(j=1; j<=N; j++)
       {
                if(s1[i-1]==s2[j-1]) m[i][j] = 1+m[i-1][j-1];
                else m[i][j] = max(m[i][j-1], m[i-1][j]);
       }
       printf("%d\n",m[M][N]); 
    }
       return 0;
}
