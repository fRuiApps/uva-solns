//distance of cost of farthest root from source + distance of farthest root from destination
#include<stdio.h>
#include<string.h>
inline int imax(const int& a, const int& b){return (a > b)? a : b;}
inline int imin(const int& a, const int& b){return (a == 0 || a > b)? b : a;}
int main()
{
    int G[105][105];
    int tc,r,n,a,b,s,e,max_value,i,kase = 1,j;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(G, 0, sizeof(G));
        scanf("%d%d",&n,&r);
        for(i =0;i<r;i++)  { scanf("%d%d",&a,&b);G[a][b] = G[b][a] = 1;}
        scanf("%d%d",&s,&e);
        for(i = 0; i < n; i++)
            for(a = 0; a < n; a++)
                for(b = 0; b < n; b++)
                    if(G[a][i] && G[i][b])
                        G[a][b] = imin(G[a][b], G[a][i] + G[i][b]);
                        
        for(i = 0; i < n; i++) G[i][i] = 0;
        max_value = 0;
        for(i = 0; i < n; i++)
        max_value = imax(max_value, G[s][i] + G[i][e]);
        printf("Case %d: %d\n", kase++, max_value);
    }
    return 0;
}
