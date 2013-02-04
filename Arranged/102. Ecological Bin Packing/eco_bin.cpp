#include<iostream>
using namespace std;
int isValid(int N)
{
    int f[3]={0},i;
    for(i=0;i<3;i++) { if((N%10)>2) return 0; else f[N%10]++; N/=10;}
    for(i=0;i<3;i++) if(f[i]!=1) return 0;
    return 1;
}               
int main()
{
    unsigned int A[3][3]={0},M,s,c,i;
    char ch[4]="BCG";
    while(cin>>A[0][0]>>A[0][2]>>A[0][1]>>A[1][0]>>A[1][2]>>A[1][1]>>A[2][0]>>A[2][2]>>A[2][1])
    {
     M=2<<30;M++;
     s=A[0][0]+A[0][1]+A[0][2]+A[1][0]+A[1][1]+A[1][2]+A[2][0]+A[2][1]+A[2][2];
     for(i=12;i<=210;i++)
     if(!isValid(i)) continue;
     else {
          if(M>(s-A[0][i/100]-A[1][(i/10)%10]-A[2][i%10])) {M=s-A[0][i/100]-A[1][(i/10)%10]-A[2][i%10];c=i;}
          }
     cout<<ch[c/100]<<ch[(c/10)%10]<<ch[c%10]<<" "<<M<<endl;
    }
    return 0;
}
