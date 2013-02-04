#include<stdio.h>
int main()
{
    char c,occ1[100000],occ2[100000],map[130],s2[100000],flag=0;
    int freq[130],max1,max2,n,i,j,k;
    scanf("%d",&n);
    while((c=getchar())!='\n');
    for(i=0;i<n;i++)
    {
     c=getchar();
     if(flag) putchar('\n'); else flag=1;
     max1=0;for(j=0;j<130;j++) freq[j]=0;
     while((c=getchar())!='\n') {if(c==' ') continue; freq[c]++;if(max1<freq[c]) max1=freq[c];}
     for(j=0;j<100000;j++) occ1[j]=0;
     for(j=0;j<130;j++) if(freq[j]) occ1[freq[j]]=j;
     k=0;max2=0;for(j=0;j<130;j++) freq[j]=0;
     while((c=getchar())!='\n') {s2[k++]=c;if(c==' ') continue; freq[c]++;if(max2<freq[c]) max2=freq[c];}
     for(j=0;j<100000;j++) occ2[j]=0;
     for(j=0;j<130;j++) if(freq[j]) occ2[freq[j]]=j;
     s2[k]='\0';map[' ']=' ';
     while(max2>-1)   {
           if(occ1[max1]!=0 && occ2[max2]!=0) {map[occ2[max2]]=occ1[max1];max1--;max2--;}
           else if(occ1[max1]==0 && occ2[max2]==0) {max1--;max2--;}
           else if(occ1[max1]==0) max1--;
           else max2--;
           }
     for(j=0;j<k;j++) putchar(map[s2[j]]);
     putchar('\n');
    }
    return 0;
}
