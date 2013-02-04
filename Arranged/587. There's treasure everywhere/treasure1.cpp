#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char s[300],d[3]="";
    int i,l,n=0,t=0,c=0;
    float x,y,temp;
    while(1)
    {
     scanf("%s",s);
     if(strcmp(s,"END")==0) break;
     x=y=0;c++;
     l=strlen(s)-1;
     for(i=0;i<=l;i++)
     {
      if(s[i]>='0' && s[i]<='9') n=n*10+s[i]-'0';
      if(s[i]>='A' && s[i]<='Z') {d[t]=s[i];t++;d[t]='\0';}
      if(s[i]==',' || s[i]=='.')
      {
       if(strcmp(d,"N")==0) y+=n;
       else if(strcmp(d,"S")==0) y-=n;
       else if(strcmp(d,"E")==0) x+=n;
       else if(strcmp(d,"W")==0) x-=n;
       else if(strcmp(d,"NE")==0) {temp=(float)n/M_SQRT2;x+=temp;y+=temp;}
       else if(strcmp(d,"NW")==0) {temp=(float)n/M_SQRT2;x-=temp;y+=temp;}
       else if(strcmp(d,"SE")==0) {temp=(float)n/M_SQRT2;x+=temp;y-=temp;}
       else if(strcmp(d,"SW")==0) {temp=(float)n/M_SQRT2;x-=temp;y-=temp;}
       n=t=0;
      }
     }
     printf("Map #%d\nThe treasure is located at (%.3f,%.3f).\nThe distance to the treasure is %.3f.\n\n",c,x,y,sqrt(x*x+y*y));
    }
    return 0;
}
