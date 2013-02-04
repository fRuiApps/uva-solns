#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n,c;
    bool arr[102][102],ref[102][102][102],f=false;
    while(cin>>n) {
                   c=0;
                   for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>arr[i][j];
                   for(i=1;i<=n;i++) 
                      for(j=1;j<=n;j++) 
                         for(k=1;k<=n;k++) 
                            if(arr[i][j]==true && arr[j][k]==true && arr[k][i]==true && (i<j && j<k || i>j && j>k)) 
                            {
                             cout<<i<<" "<<j<<" "<<k<<endl;
                             ref[i][j][k]=ref[j][k][i]=ref[k][i][j]=true;
                             c++;
                            }
                   cout<<"total:"<<c<<endl<<endl;
    }    
    return 0;
}
