#include<iostream>
using namespace std;
int main()
{
    int bin[3][3],move[3][3];
    int i,j,least,b,c,g,c1,g1,l1,l2,l,d,x,y,bgc,gbc;
    while(cin>>bin[0][0]>>bin[0][1]>>bin[0][2]>>bin[1][0]>>bin[1][1]>>bin[1][2]>>bin[2][0]>>bin[2][1]>>bin[2][2])
    {
                   
    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
    {
                    move[i][j]=bin[(i+1)%3][j]+bin[(i+2)%3][j];
                    }
    least=move[0][0]+move[1][1]+move[2][2];
    b=0,c=2,g=1;   bgc=132;             
    for(i=0;i<3;i++)
    {
        x=move[(i+1)%3][1]+move[(i+2)%3][2];
        y=move[(i+1)%3][2]+move[(i+2)%3][1]; 
        if(x>y)
        {l=y;
        g1=(i+2)%3;
        c1=(i+1)%3;
        }
        else
        if(x==y)
        {
                l=y;
                if(((i+1)%3)<((i+2)%3))
                {
                                     g1=(i+2)%3;
                                     c1=(i+1)%3;
                                     }
                  else
                  {
                      g1=(i+1)%3;
                      c1=(i+2)%3;
                      }
                      }
        else
        {
            l=x;
            g1=(i+1)%3;
            c1=(i+2)%3;
            }  
            switch(i){
                      case(0):if(c1==1)
                                  gbc=123;
                                  else
                                  gbc=132;
                                  break;
                       case(1):if(c1==0)
                                gbc=213;
                                else
                                gbc=312;
                                break;
                       default:if(c1==0)
                                gbc=231;
                                else
                                gbc=321;
                                }                                       
        if(least>(l+move[i][0]))
        {
                                least=l+move[i][0];
                                 g=g1;
                                 c=c1;
                                 b=i;
                                 }
          if(least==(l+move[i][0]))
          {
             if(bgc>gbc)
             {
                      least=l+move[i][0];
                      bgc=gbc;g=g1;
                      c=c1;
                      b=i;
                      }
                      }                                                              
}
switch(b){
          case(0):if(c==1)
                   cout<<"BCG: "<<least;
                   else
                   cout<<"BGC: "<<least;
                   break;
            case(1):if(c==0)
                     cout<<"CBG: "<<least;
                     else
                     cout<<"GBC: "<<least;
                     break;
            default:if(c==0)
                     cout<<"CGB: "<<least;
                     else
                     cout<<"GCB: "<<least;
                     }
    cout<<endl;
    }
}                       
