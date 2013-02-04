#include<iostream>
using namespace std;
int LCS(char * A,char * B,int a,int b)
{
    int L[a+1][b+1],dir[40][40],i,j;
    for(i=0;i<=a;i++) L[i][0]=0;
    for(i=0;i<=b;i++) L[0][i]=0;
    for(i=1;i<=a;i++) {
                       for(j=1;j<=b;j++) 
                         {
                          L[i][j]=((A[i]==B[j])?(1+L[i-1][j-1]):((L[i][j-1]>L[i-1][j])?L[i][j-1]:L[i-1][j]));
                          dir[i][j]=((A[i]==B[j])?0:((L[i][j-1]>L[i-1][j])?2:1));
                         }
    }
    return L[a][b];
}
int main()
{
    int cases=0,a,b;
    char A[105],B[105],c;
    while(true)
    {
     a=b=1;cases++;
     while((c=getchar())!='\n') A[a++]=c;A[a]='\0';a--;if(A[a]=='#') break;
     while((c=getchar())!='\n') B[b++]=c;B[b]='\0';b--;
     cout<<"Case #"<<cases<<": you can visit at most "<<LCS(A,B,a,b)<<" cities.\n";
    }
    return 0;
}
