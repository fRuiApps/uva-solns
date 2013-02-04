#include<stdio.h>
int main()
{
    int freq[27]={0},m=0,i,t,c;
    while((c=getchar())!=EOF)
    {
     if(c>='A' && c<='Z') freq[c-'A']++;
     else if(c>='a' && c<='z') freq[c-32-'A']++;
    }
    while(true) {
      m=0;
      for(i=0;i<26;i++) {if(freq[i]>m) {m=freq[i];t=i;}}
      if(m==0) break;
      printf("%c %d\n",t+'A',m);
      freq[t]=0;
      }
    return 0;
}
