//major consideration if there exists a flight betn a and b dosnt mean there exists a flight between b and a
#include<stdio.h>
#define N 26
int main()
{
    int a,b,i,n,tc,j;
    char c,d;
    scanf("%d",&tc);
    while(tc--)
    {
           bool G[2][N][N] = {0},flag = 1;
           for(j = 0;j<2;j++)
           {
                 scanf("%d\n",&n);
                 for(i=0;i<n;i++)
                 {
                       c = getchar();getchar();d = getchar();getchar();
                       G[j][c - 'A'][d - 'A']  = 1;
                 }
           }
           for(j = 0;j<2;j++)
           {
               for(i = 0; i < N; i++)
                for(a = 0; a < N; a++)
                    for(b = 0; b < N; b++)
                         G[j][a][b] |= (G[j][a][i] & G[j][i][b]); 
           }
           
           for(a = 0; a < N; a++)
                for(b = 0; b < N; b++)
                if(G[0][a][b] ^ G[1][a][b]) {flag = 0;break;}
                
           if(flag == 0) printf("NO\n");else printf("YES\n");
           if(tc) printf("\n");
    }
    return 0;
}
