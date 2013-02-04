#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int poly[100],i=0,x,c,j,s;
    bool input=true;
    while((c=getchar())!=EOF) {
                              putchar(c);
    if(input) {cin>>poly[i];i++;}
    if(c=='\n') {cout<<"End line\n";input=((input==true)?false:true);if(input==true) {cout<<endl;i=0;}}
    if(!input) {cin>>x;s=0;for(j=0;j<i;j++) s+=poly[j]*(int)pow(x,j);cout<<s<<" ";}
    }
    return 0;
}
