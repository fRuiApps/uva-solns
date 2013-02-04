#include<iostream>
using namespace std;
int main()
{
    int r,i,j,s,f,n;
    char c,used[30],guessed[30];
    while(true)  {
                  s=f=j=n=0;
                  cin>>r;
                  if(r==-1) break;
                  while((c=getchar())!='\n');
                  for(i=0;i<30;i++) used[i]=guessed[i]=0;
                  while((c=getchar())!='\n') if(!used[c-'a']) {used[c-'a']=1;n++;}
                  while((c=getchar())!='\n') {if(!guessed[c-'a']) {if(used[c-'a']) f++; else j++; guessed[c-'a']=1;if(j==7 || f==n) break;}}
                  if(c!='\n') while((c=getchar())!='\n');
                  cout<<"Round "<<r<<endl;
                  if(j==7) cout<<"You lose.\n";
                  else if(f==n) cout<<"You win.\n";
                  else cout<<"You chickened out.\n";
                 }
    return 0;
}
