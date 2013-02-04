#include<stdio.h>
int fun(int x,int y,int k,int px,int py) /* returns the number of squares containing (px,py) among */
{										 /* those which are generated from the square with size k */
     int f=0;							 /* and center (x,y)	*/
     if( px>=(x-k) && px<=(x+k) && py>=(y-k) && py<=(y+k)) f=1;
     if(k==0) return f;
     return f+fun(x-k,y-k,k/2,px,py)+fun(x+k,y-k,k/2,px,py)+fun(x+k,y+k,k/2,px,py)+fun(x-k,y+k,k/2,px,py);
}
int main()
{
    int k,x,y;
    while(1)
    {
     scanf("%d %d %d",&k,&x,&y);
     if(k==0) break;
     printf("%3d\n",fun(1024,1024,k,x,y));
    }
    return 0;
}
