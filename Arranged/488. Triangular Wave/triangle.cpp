#include<stdio.h>
int main()
{
    int n,a,f,i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=(n-1);i++)
    {
     scanf("%d %d",&a,&f);
     for(k=1;k<=f;k++){
     for(j=1;j<=a;j++)
     {
      for(l=1;l<=j;l++)
      printf("%d",j);
      printf("\n");
     }
     for(j=(a-1);j>=1;j--)
     {
      for(l=1;l<=j;l++)
      printf("%d",j);
      printf("\n");
     }
     printf("\n");
    }
    }
    scanf("%d %d",&a,&f);
     for(k=1;k<=f;k++){
     for(j=1;j<=a;j++)
     {
      for(l=1;l<=j;l++)
      printf("%d",j);
      printf("\n");
     }
     for(j=(a-1);j>=1;j--)
     {
      for(l=1;l<=j;l++)
      printf("%d",j);
      printf("\n");
      }
     if(k<f) printf("\n");
    }
    return 0;
}
     
