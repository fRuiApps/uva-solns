
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<long>primes;
bool isprime(long a)
{   int n=(int)sqrt(a);
    if((a&1)==0)
        return false;
    for(int i=3;i<=n;i+=2)
        if(a%i==0) 
            return false;
    return true;
}
int main(){
    long n;
    primes.push_back(2);
    primes.push_back(3);
    for(long i=5;i<=46338;i+=2)
        if(isprime(i))
            primes.push_back(i);
    cin>>n;
    while(n!=0){
        cout<<n<<" = ";
        if(n<0){
            cout<<"-1 x ";
            n=n*-1;
        }
        int i=0;
        while(n>1){
            if(n%primes[i]==0){
                n/=primes[i];
                if(n!=1)
                    cout<<primes[i]<<" x ";                
                else
                    cout<<primes[i];                
            }
            else
                i++;
            if(i>=primes.size()){
                cout<<n;
                break;
            }
        }
        cout<<endl;
        cin>>n;
    }
    return 0;
}
