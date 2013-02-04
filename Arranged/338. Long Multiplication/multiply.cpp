#include<stdio.h>
#include<conio.h>

void generate_prod(int*,int*,int,int,int);
void add(int*,int*);

void main()
{
 clrscr();

 int c,l1=0,l2=0,sw=1,i;
 int n1[20]={0},n2[20]={0},r[40]={0},temp[40];

 while((c=getchar())!='\n')
 	{
    if(c==',')
    	{
    	 sw=0;
       continue;
      }
    if(sw)
    	n1[l1++]=c-'0';
    else
    	n2[l2++]=c-'0';
   }

 for(i=l2-1;i>=0;i--)
 	{
    generate_prod(temp,n1,l1,n2[i],l2-i-1);
    add(r,temp);
   }

 printf("\n");

 for(i=39;i>=0;i--)
 	{
    if(r[i]>0)
    	sw=1;

    if(sw)
    	printf("%d",r[i]);
   }
   
 getch();
}
void generate_prod(int *p,int *n1,int size,int n,int st)
{
 int i,sum,carry=0,j;
 j=st;
 for(i=0;i<40;i++)
 	p[i]=0;
 for(i=size-1;i>=0;i--)
 	{
    sum=(n1[i]*n+carry)%10;
    carry=(n1[i]*n+carry)/10;
    p[j++]=sum;
   }
 p[j]=carry;
}
void add(int* a1,int* a2)
{
 int i,sum,carry=0;
 for(i=0;i<30;i++)
 	{
    sum=(a1[i]+a2[i]+carry)%10;
    carry=(a1[i]+a2[i]+carry)/10;
    a1[i]=sum;
   }
 }


