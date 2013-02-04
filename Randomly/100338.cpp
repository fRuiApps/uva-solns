#include<iostream>
using namespace std;
int main()
{
     
    string st;
    long long fact[21];fact[0] = 1;
    long long  ntc,cnt = 1,i,l,val,ans,r;
    for(i=1;i<=20;i++) fact[i] = i*fact[i-1];
    cin>>ntc;
    while(ntc--)
    {
                int present[26] = {0};
                val = 0;
                cin>>st;
                l = st.size();
                if(l<=20) 
                {
                    ans = fact[l];      
                    for(i =0;st[i];i++)
                    present[st[i]-'A']++;
                    for(i=0;i<26;i++)  ans /= fact[present[i]];
                    cout<<"Data set "<<cnt++<<": "<<ans<<endl;       
                }
                else 
                cout<<cout<<"Data set "<<cnt++<<": 0"<<endl;
                
    }
    return 0;
}
 
