#include<iostream>
using namespace std;
int list[1010][30];
bool isMatching(int j,int * freq)
{
     int k;
     for(k=0;k<30;k++) if(list[j][k]>freq[k]) return false;
     return true;
}
int main()
{
    char c;
    int i=0,j=0,freq[30]={0},n;
    while((c=getchar())!='#') {
                               if(c=='\n') i++;
                               else list[i][c-'a']++;
                              }
    c=getchar(); //for the newline
    while((c=getchar())!='#') {
                               if(c=='\n') {
                                            n=0;
                                            //for(j=0;j<30;j++) cout<<freq[j]<<" ";cout<<endl;
                                            for(j=0;j<i;j++) if(isMatching(j,freq)) n++;
                                            cout<<n<<endl;n=0;for(j=0;j<30;j++) freq[j]=0;
                                           }
                               else {
                                     if(c!=' ') freq[c-'a']++;
                                    }
    } 
    return 0;   
}
