#include<stdio.h>
int isMutant(char * s,int i,int j)
{
    if(i==j) if(s[i]=='A') return 0; else return 1;
    else {
          if(s[j]=='B' && s[j-1]=='A') return isMutant(s,i,j-2);
          else if(s[i]=='B' && s[j]=='A') return isMutant(s,i+1,j-1);
          else return 1;
    }
}
int main()
{
    int N,i,l;
    char S[1000];
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s",S);l=strlen(S);
        if(isMutant(S,0,l-1)) printf("MUTANT\n");
        else {
              if(l==1) printf("SIMPLE\n");
              else if(S[l-2]=='A' && S[l-1]=='B') printf("FULLY-GROWN\n");
              else if(S[0]=='B' && S[l-1]=='A') printf("MUTAGENIC\n");
        }
    }
    return 0;
}
