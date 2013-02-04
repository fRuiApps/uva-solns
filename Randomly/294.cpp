#include<stdio.h>
#define large 100000000
unsigned long int ans[large] = {0};
bool done[1000000000] = {0};
unsigned long int calc(unsigned long int num)
{
         unsigned long int i,j,answ = 0;
         for(j = 2;j*j<=num;j++)
         if(num%j==0) answ += 2;
         if((j-1)*(j-1)==num) answ--;
         answ += 2;
         done[num] = 1;
         if(num<large) {ans[num] = answ;return 0;}
         else return answ;
         
}
int main()
{
    unsigned long int i,j,num,max,l,h,ntc,dummy;
    scanf("%lu",&ntc);
    while(ntc--)
    {
        max = 0;        
        scanf("%lu%lu",&l,&h);
        for(i = l;i<=h;i++)
        {
              if(i<large)
              {
                 if(done[i] == 0) {dummy = calc(i);}
                 if(max<ans[i]) {max = ans[i];num = i;}
              }
              else
              {
                  dummy = calc(i);
                  if(max<dummy) {max = dummy;num = i;}
              }
        }
        printf("Between %lu and %lu, %lu has a maximum of %lu divisors.\n",l,h,num,max);
    }
    return 0;
}

                    
                  
          
    
