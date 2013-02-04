#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    long i,s[105] = {0},prev = 0,ntc,a,b,sum,cnt = 1,temp;
    for(i = 0;i<=100;i++)
    {
          temp = i;
          if(temp & 1)
          { 
                  s[i] = prev + i;
                  prev = s[i];
          }
          else s[i] = prev;
           
    }
    //cin>>ntc;
    scanf("%d",&ntc);
   
    for(i = 0;i<ntc;i++)
    {
      
        s1:        
        sum = 0;        
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        if(a == b)
        {
             if(a&1 && b&1) 
             {
                    //cout<<"Case "<<cnt++<<": "<<a<<endl;goto s1;
                    printf("Case %d: %d\n",cnt++,a);goto s1;
                    }
             else
             {//cout<<"Case "<<cnt++<<": 0"<<endl;goto s1;
             printf("Case %d: 0\n",cnt++);goto s1;}
        }
         if(a&1) a--;
         //cout<<"Case "<<cnt++<<": "<<s[b]-s[a]<<endl;
         printf("Case %d: %d\n",cnt++,s[b]-s[a]);goto s1;
    }
    return 0;
}    
        
