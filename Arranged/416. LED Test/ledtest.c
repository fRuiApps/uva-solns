#include<stdio.h>
int rep[10]={1,79,18,6,76,36,32,15,0,4},A[128][10],def[128][10];
int toNumber(char * s)
{
    int i,n=0;for(i=0;s[i]!='\0';i++) if(s[i]=='N') n+=(1<<(6-i));return n;
}
int check(int a,int b,int r)
{
    while(a||b) {if((a&1)==1 && (b&1)==0 && (r&1)==0) return 0;a>>=1;b>>=1;r>>=1;}
    return 1;
}
int isMatch(int * seq,int st,int prev,int size,int d)
{
    /*printf("%d %d\n",prev,d);*/
    if(prev==0 && st<=size) return 0;
    if(st>size) return 1;if(A[seq[st]][prev-1]&&check(d,def[seq[st]][prev-1],rep[prev-1])) {return isMatch(seq,st+1,prev-1,size,(def[seq[st]][prev-1]|d));} else return 0;
}
int main()
{
    int i,j,N,seq[11];
    char s[10];
    for(i=0;i<128;i++) for(j=0;j<10;j++) if((i&rep[j])==rep[j]) {A[i][j]=1;def[i][j]=i^rep[j];}
    while(1) {
        scanf("%d",&N);if(!N) break;
        for(i=0;i<N;i++) {
            scanf("%s",s);seq[i]=toNumber(s);
            /*printf("%d : ",seq[i]);
            for(j=0;j<10;j++) if(A[seq[i]][j]) printf("%d ",j);printf("\n");*/
        }
        for(i=0;i<10;i++) {if(A[seq[0]][i]&&isMatch(seq,1,i,N-1,def[seq[0]][i])) {printf("MATCH\n");break;}}
        if(i==10) printf("MISMATCH\n");
    }
    return 0;
}
