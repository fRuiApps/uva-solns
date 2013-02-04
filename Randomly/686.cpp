#include<iostream>
using namespace std;

int main(){

bool  sieve[32767] = {0};
unsigned long int i,j,n,pair = 0;

for(i = 2;i<=182;i++){
for(j = i*i;j<32767;j+=i)
sieve[j] = 1;
}

while(cin>>n  && n!= 0){

for(i = 2;i<=n/2;i++){
if(sieve[i] == 0  && sieve[n-i] == 0)
pair++;
}

cout<<pair<<endl;
pair = 0;

}
return 0;
}
