#include<stdio.h>
int main()
{
    char c;
    int freq[128]={0},m=0,i;
    while((c=getchar())!=EOF)
    {
     if(c=='\n') {for(i=0;i<128;i++) if(freq[i]==m) printf("%c",i); 
                  printf(" %d\n",m);
                  m=0;
                  for(i=0;i<128;i++) freq[i]=0;}
     else {if(c>='A' && c<='Z' || c>='a' && c<='z') freq[c]++; if(m<freq[c]) m=freq[c];}
    }
    return 0;
}
