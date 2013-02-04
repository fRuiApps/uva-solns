#include<stdio.h>
int main()
{
    unsigned int N;
    while(scanf("%u",&N)!=EOF) {
    printf("%d converts to %d\n",N,((N<<24)+(((N>>8)<<24)>>8)+(((N>>16)<<24)>>16)+(N>>24)));
    }
    return 0;
}
