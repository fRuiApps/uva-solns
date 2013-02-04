#include<stdio.h>
#include<math.h>
#define N 205

inline double abs(const int &a){return(a<0?-a:a);}
inline double imin(const double& a, const double& b){return (a == 0 || a > b)? b : a;}
inline double imax(const double& a, const double& b){return ( a < b)? b : a;}

int main()
{
    
    int n,i,j,a,b,kase = 1;
    while(scanf("%d",&n) && n != 0)
    {                          
        
        if(n<2) break;
        printf("Scenario #%d\n",kase++);
        double dist[N][N] = {0};
        int array[N][2] = {0};
        
        for(int i = 0; i < n; i++)
            scanf("%d%d",&array[i][0],&array[i][1]);
        
        for( i = 0; i < n; i++)
        {
            dist[i][i] = 0.0;
            for( j = i+1; j < n; j++)
                dist[i][j] = dist[j][i] = sqrt(pow(abs(array[i][0] - array[j][0]), 2.0) + pow(abs(array[i][1] - array[j][1]), 2.0));
                 
        }     
        
        for(i = 0; i <n; i++)
            for(a = 0; a <n; a++)
                for(b = 0; b <n; b++)
                    if(dist[a][i] != 0 && dist[i][b] != 0)
                        dist[a][b] = imin(dist[a][b], imax(dist[a][i] , dist[i][b]));
        printf("Frog Distance = %.3f\n\n",dist[0][1]);
    }
    return 0;
            
}
            
                  
       
