#include<stdio.h>
#include<string.h>
int main()
{
    char c,s[140],stack[140];
    int sp=-1,i,j,n,l,k;
    scanf("%d",&n);
    c=getchar();
    for(i=1;i<=n;i++)
    {
     sp=-1;k=0;
     while(1)
     {
      c=getchar();
      s[k++]=c;
      if(c=='\n' || c==EOF) {s[k-1]='\0';break;}
     }
     l=strlen(s);
     for(j=0;j<l;j++)
     {c=s[j];
     if(c=='[' || c=='(') stack[++sp]=c;
     else if(c==')') if(sp>=0 && stack[sp]=='(') sp--;
                     else break;
     else if(c==']') if(sp>=0 && stack[sp]=='[') sp--;
                     else break;
     }
     if(j==l && sp==-1) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}
