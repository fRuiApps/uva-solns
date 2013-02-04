#include<stdio.h>
int main()
{
    int i,j,n,onecol,onerow,poscol,posrow;
    while(scanf("%d",&n) && n != 0)
    {
        bool  colsum[101] = {0},rowsum[101] = {0}, arr[101][101] = {0} ;
        onecol = onerow = poscol = posrow = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&arr[i][j]);
                rowsum[i] ^= arr[i][j];
            }
            if(rowsum[i] == 1 ) {onerow++;posrow = i;} 
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            colsum[i] ^= arr[j][i];        
            if(colsum[i]==1){onecol++;poscol = i;}
        }
        if(onecol  == 0 && onerow  == 0) printf("OK\n");
        else if((onecol&1 ==0)&&(onerow&1==0)&& onerow && onecol) printf("OK\n");
        else if(onecol == 1 && onerow == 1) printf("Change bit (%d,%d)\n",posrow+1,poscol+1);
        else printf("Corrupt\n");
        
    }
    return 0;
}
