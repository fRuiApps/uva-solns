#include<iostream>
using namespace std;
bool isSame(char * A,char * B,int a,int b,int c,int d,int e,int f)
{
     if(A[1]==B[a] && A[2]==B[b] && A[3]==B[c] && A[4]==B[d] && A[5]==B[e] && A[6]==B[f]) return true; else return false;
}
int main()
{
    char A[10],B[10],S[15];
    int i,j;
    while(cin>>S) {
                   for(i=1;i<=6;i++) {A[i]=S[i-1];B[i]=S[i+5];}
                   A[7]=B[7]='\0';
                   if(isSame(A,B,1,2,3,4,5,6)||isSame(A,B,1,4,2,5,3,6)||isSame(A,B,1,5,4,3,2,6)||isSame(A,B,1,3,5,2,4,6)||isSame(A,B,6,2,4,3,5,1)||isSame(A,B,6,3,2,5,4,1)||isSame(A,B,6,4,5,2,3,1)||isSame(A,B,6,5,3,4,2,1)||isSame(A,B,3,2,6,1,5,4)||isSame(A,B,3,1,2,5,6,4)||isSame(A,B,3,5,1,6,2,4)||isSame(A,B,3,6,5,2,1,4)||isSame(A,B,4,1,5,2,6,3)||isSame(A,B,4,2,1,6,5,3)||isSame(A,B,4,6,2,5,1,3)||isSame(A,B,4,5,6,1,2,3)||isSame(A,B,2,3,1,6,4,5)||isSame(A,B,2,1,4,3,6,5)||isSame(A,B,2,4,6,1,3,5)||isSame(A,B,2,6,3,4,1,5)||isSame(A,B,5,1,3,4,6,2)||isSame(A,B,5,3,6,1,4,2)||isSame(A,B,5,6,4,3,1,2)||isSame(A,B,5,4,1,6,3,2))
                   cout<<"TRUE\n"; 
                   else cout<<"FALSE\n";
    }
    return 0;
}
