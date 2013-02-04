#include<stdio.h>
#define min(a,b) (a<b?a:b)
int main()
{
    char a[1005],b[1005],ans[1005];
    int i,j,cnt;
    while(gets(a))
    {
        gets(b);
        ans[0] = '\0';cnt = 0;int A[26] = {0};int B[26] = {0};
        for(i=0;a[i];i++) A[a[i]-'a']++;
        for(i=0;b[i];i++) B[b[i]-'a']++;
        for(i = 0;i<26;i++)
        {
              for(j=0;j<min(A[i],B[i]);j++)
              ans[cnt++] =  (char)(i + 'a'); 
        }
        ans[cnt]= '\0';
        printf("%s\n",ans);
    }
    return 0;
}
                                 
