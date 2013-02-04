#include<iostream>
using namespace std;
struct ds {char letter; int cnt;};
int main()
{
   
    int i,j,maxu,maxl,k,l;
    char c;
    ds up[26],low[26],temp;
    for(i =0;i<26;i++){ up[i].letter = i+'A'; up[i].cnt = 0;}
    for(i =0;i<26;i++){ low[i].letter = i+'a'; low[i].cnt = 0;}
    while((c=getchar())!=EOF)
    {
        if(c != '\n')                     
        {if(c>64 && c<91) up[c-'A'].cnt++; 
         if(c > 96 && c<123)  low[c-'a'].cnt++;}
        else
        {   for(i=0;i<26;i++){for(j=0;j<26;j++) if(up[i].cnt>up[j].cnt) { temp = up[i] ;up[i] =  up[j];up[j] = temp;}}
            for(i=0;i<26;i++){for(j=0;j<26;j++) if(low[i].cnt>low[j].cnt) {temp = low[i] ;low[i] =  low[j];low[j] = temp;}}
            i = j = k = l = 0;maxu = up[0].cnt;maxl = low[0].cnt;
            if(maxu>maxl) { while(up[i].cnt >= maxu && i<26) {cout<<up[i].letter;i++;}cout<<" "<<up[0].cnt;}
            else if(maxu<maxl){ while(low[j].cnt >= maxl && j<26){  cout<<low[j].letter;j++;}cout<<" "<<low[0].cnt;}
            else {while(up[k].cnt >= maxu && k<26)  {cout<<up[k].letter;k++;}while(low[l].cnt >= maxl && l<26) {cout<<low[l].letter;l++;}cout<<" "<<low[0].cnt;}
            for(i =0;i<26;i++){ up[i].letter = i+'A'; up[i].cnt = 0;} for(i =0;i<26;i++){ low[i].letter = i+'a'; low[i].cnt = 0;}
            cout<<endl;}
    }
    return 0;
}
