#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    char line[100];
    unsigned long int i,l,sum;
    while((cin>>line)  && (line[0] != '0'))
    {
                    sum = 0;
                    l = strlen(line);
                    for(i =0;i<l;i++)
                    sum += (line[i] - '0')*(pow(2,l-i)-1);
                    cout<<sum<<endl;
    }
    return 0;
}
                    
