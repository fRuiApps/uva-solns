#include<stdio.h>

inline int imin(const int& a, const int& b){return (a == 0 || a > b)? b : a;}
inline int imax(const int& a, const int& b){return ( a < b)? b : a;}
int main()
{
    
    int c,s,q,wt,i,a,b,kase = 1;
    while((scanf("%d%d%d",&c,&s,&q))&& (c||s||q))
    {                          
            if(c == 0) break;
            if(kase>1)printf("\n");                   
            printf("Case #%d\n",kase++);
            int g[105][105] = {0};
            for(i = 1;i<=s;i++)
            {
                  scanf("%d%d%d",&a,&b,&wt);
                  g[a][b] = g[b][a] = wt;
            }
            for(i = 1; i <=c; i++)
            for(a = 1; a <=c; a++)
                for(b = 1; b <=c; b++)
                    if(g[a][i] && g[i][b])
                        g[a][b] = imin(g[a][b], imax(g[a][i] , g[i][b]));
            
            if(q>0) ;else {printf("no path\n");break;}
            for(i = 1;i<=q;i++)
            {
                  scanf("%d%d",&a,&b);
                  if(g[a][b]) printf("%d\n",g[a][b]);
                  else printf("no path\n");
            }
            
    }
    return 0;
}
            
                  
       
