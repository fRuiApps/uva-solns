#include<cstdio>
using namespace std;
int main()
{
    int n,sum,i;
    printf("PERFECTION OUTPUT\n");
    while((scanf("%d",&n))&&(n!= 0))
    {
                     
                     sum = 0;
                     for(i = 1;i<=(n/2);i++)
                     {
                           if(n%i == 0)
                           sum += i;
                     }
                     if(sum == n)
                     printf("%5d%s\n",n,"  PERFECT");
                     else
                     if(sum<n)
                     printf("%5d%s\n",n,"  DEFICIENT");
                     else
                     printf("%5d%s\n",n,"  ABUNDANT");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
                           
                     
