#include<stdio.h>
int main()
{
    int regions[25][4],icons[51][2],dist2[51],clicks[100000][2],i=1,r=0,j,f=0,M,lx,ly,rx,ry,ck=0,x;
    char t,c;
    while(1) {
     scanf("%c %d %d %d %d",&c,&lx,&ly,&rx,&ry);
     if(c=='R') {regions[r][0]=lx;regions[r][1]=ly;regions[r][2]=rx;regions[r][3]=ry;r++;}
     if(c=='I') {icons[i][0]=lx;icons[i][1]=ly;i++;}
     if(c=='M') {clicks[ck][0]=lx;clicks[ck][1]=ly;ck++;}
     if(c=='#') break;
    }
    for(x=0;x<ck;x++) {
     t='\0';
     lx=clicks[x][0];ly=clicks[x][1];
     for(j=0;j<r;j++) if(lx>=regions[j][0] && lx<=regions[j][2] && ly>=regions[j][1] && ly<=regions[j][3]) t=j+'A';
     if(t) printf("%c\n",t);
     else { M=300000;
            for(j=1;j<i;j++) {
                dist2[j]=(icons[j][0]-lx)*(icons[j][0]-lx) + (icons[j][1]-ly)*(icons[j][1]-ly);
                if(M>dist2[j]) M=dist2[j]; }
            for(j=1;j<i;j++) if(dist2[j]==M) printf("%3d",j); printf("\n");
           }
     }
     return 0;
}
