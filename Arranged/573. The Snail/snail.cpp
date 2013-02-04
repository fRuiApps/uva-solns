#include<iostream>
using namespace std;
int main()
{
    int H,U,D,F,i,f;
    float U1,c,R;
    while(true) {
                cin>>H>>U>>D>>F;
                R=((float)(F*U))/100;
                if(H==0) break;
                c=0.0;i=0;U1=U;f=0;
                while(true) {
                             i++;
                             c+=U1;
                             if(c>H) {f=1;break;}
                             c-=D;if(c<0) break;
                             U1-=R;if(U1<0) U1=0.0;
                } 
                cout<<((f)?"success ":"failure ");
                cout<<"on day "<<i<<endl;
    }
    return 0;
}
