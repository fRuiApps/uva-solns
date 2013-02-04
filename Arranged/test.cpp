#include<iostream>
using namespace std;
int main(int argc,char *argv[])
{
    char i=1,c,c1;
    FILE *f1,*f2;
    f1=fopen(argv[1],"r");
    f2=fopen(argv[2],"r");
    while((c=getc(f1))!=EOF)
    {
     c1=getc(f2);
     cout<<c<<" "<<c1<<endl;
     if(c!=c1) {i=0;break;}
    }
    if(i) cout<<"The files match.\n";
    else cout<<c<<" and "<<c1<<" do not match.\n";
    return 0;
} 
