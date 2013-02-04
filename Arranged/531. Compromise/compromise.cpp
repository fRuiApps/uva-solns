#include<iostream>
#include<string.h>
using namespace std;
void print_LCS(char A[][40],int dir[][40],int a, int b)
{
     if(a==0 || b==0) {}
     else if(dir[a][b]==0)  {print_LCS(A,dir,a-1,b-1);cout<<A[a]<<" ";}
     else if(dir[a][b]==1) print_LCS(A,dir,a-1,b);
     else print_LCS(A,dir,a,b-1);
}
int LCS(char A[][40],char B[][40],int a,int b)
{
    int L[a+1][b+1],dir[40][40],i,j;
    for(i=0;i<=a;i++) L[i][0]=0;
    for(i=0;i<=b;i++) L[0][i]=0;
    for(i=1;i<=a;i++) {
                       for(j=1;j<=b;j++) 
                         {
                          L[i][j]=((strcmp(A[i],B[j])==0)?(1+L[i-1][j-1]):((L[i][j-1]>L[i-1][j])?L[i][j-1]:L[i-1][j]));
                          dir[i][j]=((strcmp(A[i],B[j])==0)?0:((L[i][j-1]>L[i-1][j])?2:1));
                         }
    }
    print_LCS(A,dir,a,b);
    cout<<"\b"<<endl;
    return L[a][b];
}
int main()
{
    char A[105][40],B[105][40],c,c1;
    int a,b,i,j,k;bool f;
    while(true)
    {
     a=b=1;f=false;c1=' ';i=j=0;
     while((c=getchar())!='#') {A[a][i++]=c; 
                                if((c==' ' || c=='\n') && c1!=' ' && c1!='\n') {A[a][i-1]='\0';a++;i=0;}
                                else if(c==' ' || c=='\n') i--;
                                c1=c;
                                if(c==EOF) {f=true;break;}
     }
     c=getchar();
     if(f || c==EOF) break;
     c1=' ';
     while((c=getchar())!='#') {B[b][j++]=c; 
                                if((c==' ' || c=='\n') && c1!=' ' && c1!='\n') {B[b][j-1]='\0';b++;j=0;}
                                else if(c==' ' || c=='\n') j--;
                                c1=c;
                                }
     LCS(A,B,a-1,b-1);
    } 
    return 0;
}
