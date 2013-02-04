#include<iostream>
using namespace std;

#define MAX 205
#define MAXI(a,b) ( (a>b)?(a):(b) )
int main()
{    

int x[MAX],y[MAX],z[MAX],ht[MAX],t;
int n,c=0;
while(cin>>n && n)
    {    
    c++;
    for(int i=0;i<n;i++) { cin>>x[i]>>y[i]>>z[i];    
                            if(x[i]>y[i]) t=x[i],x[i]=y[i],y[i]=t;
                            if(y[i]>z[i]) t=y[i],y[i]=z[i],z[i]=t;
                            x[n+i]=x[i]; y[n+i]=z[i]; z[n+i]=y[i];
                            x[2*n+i]=y[i]; y[2*n+i]=x[i]; z[2*n+i]=z[i];
                            x[3*n+i]=y[i]; y[3*n+i]=z[i]; z[3*n+i]=x[i];
                            x[4*n+i]=z[i]; y[4*n+i]=x[i]; z[4*n+i]=y[i];
                            x[5*n+i]=z[i]; y[5*n+i]=y[i]; z[5*n+i]=x[i];
                           //Using all six permutations. You can use a block any number of times but practically max 3 times 
                           //due to constraints
                            }
   
   n*=6;
    
     
   for(int i=0;i<n;i++)     
           for(int j=i+1;j<n;j++)
                   {
                   if(x[j]<x[i])
                            {
                            t=x[j],x[j]=x[i],x[i]=t;
                            t=y[j],y[j]=y[i],y[i]=t;
                            t=z[j],z[j]=z[i],z[i]=t;
                            }     
                   }
/*
    cout<<"-----------------------------------------------------------"<<endl;
    for(int i=0;i<n;i++) cout<<x[i]<<","<<y[i]<<","<<z[i]<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
*/
   for(int i=0;i<n;i++) ht[i]=z[i];
   
   for(int i=1;i<n;i++) 
         for(int j=0;j<i;j++)
            {
             if( (y[j]<y[i]) && (x[j]<x[i]) )  
                        if( (ht[j]+z[i]) >=ht[i]) ht[i]=ht[j]+z[i];
            }
    int best=0;
     for(int i=0;i<n;i++) best=MAXI(best,ht[i]);
    cout<<"Case "<<c<<": maximum height = "<<best<<endl;
    }
return 0;
}
