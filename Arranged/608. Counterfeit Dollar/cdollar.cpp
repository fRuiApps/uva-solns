#include<iostream>
using namespace std;
int main()
{
    char l[10],r[10],result[5],ls[10],rs[10],ress[5],sieve[91],sieve1[91],status[7];
    int n,i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
    {
     for(j='A';j<='L';j++) sieve[j]=1;
     for(j=1;j<=3;j++)
     {
      cin>>l>>r>>result;
      if(result[0]=='e') for(k=0;l[k]!='\0';k++) sieve[l[k]]=sieve[r[k]]=0;
      else {
            strcpy(ls,l); strcpy(rs,r); strcpy(ress,result);
            for(k='A';k<='L';k++) sieve1[k]=0;
            for(k=0;l[k]!='\0';k++) sieve1[l[k]]=sieve1[r[k]]=1;
            for(k='A';k<='L';k++) sieve[k]=(sieve[k] && sieve1[k]);
           } 
     }
     for(j='A';j<='L';j++)  if(sieve[j]) break;
     for(k=0;ls[k]!='\0';k++) { 
                               if(ls[k]==j)
                                  {if(ress[0]=='u') strcpy(status,"heavy."); else strcpy(status,"light."); break;}
                               else if(rs[k]==j)
                                  {if(ress[0]=='u') strcpy(status,"light."); else strcpy(status,"heavy."); break;}
     }
     cout<<(char)j<<" is the counterfeit coin and it is "<<status<<endl;
     }
    return 0;
}
