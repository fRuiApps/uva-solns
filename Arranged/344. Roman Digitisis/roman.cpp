#include<iostream>
using namespace std;
int main()
{
    int freq[101][5]={{0,0,0,0,0},{1,0,0,0,0},{2,0,0,0,0},{3,0,0,0,0},{1,1,0,0,0},{0,1,0,0,0},{1,1,0,0,0},{2,1,0,0,0},{3,1,0,0,0},{1,0,1,0,0},{0,0,1,0,0}},sum[101][5],n,i,j;
    char map[6]="ivxlc";
    freq[40][0]=0;freq[40][1]=0;freq[40][2]=1;freq[40][3]=1;freq[40][4]=0;
    freq[50][0]=0;freq[50][1]=0;freq[50][2]=0;freq[50][3]=1;freq[50][4]=0;
    freq[90][0]=0;freq[90][1]=0;freq[90][2]=1;freq[90][3]=0;freq[90][4]=1;
    freq[100][0]=0;freq[100][1]=0;freq[100][2]=0;freq[100][3]=0;freq[100][4]=1;
    for(i=11;i<100;i++) if(i!=40 && i!=50 && i!=90) for(j=0;j<5;j++) if(i%10) freq[i][j]=freq[(i/10)*10][j]+freq[i%10][j];else freq[i][j]=freq[i-10][j]+freq[10][j];
    for(j=0;j<5;j++) sum[0][j]=freq[0][j];
    for(i=1;i<=100;i++) for(j=0;j<5;j++) sum[i][j]=sum[i-1][j]+freq[i][j];
    while(true) {
                  cin>>n;if(n==0) break;
                  cout<<n<<":";
                  for(i=0;i<4;i++) cout<<" "<<sum[n][i]<<" "<<map[i]<<",";
                  cout<<" "<<sum[n][4]<<" "<<map[4]<<"\n";
     }
    return 0;
}
