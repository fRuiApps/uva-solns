#include<iostream>
using namespace std;
int min(int a,int b,int c,int &t)
{
    if(a<=b && a<=c) {t=2;return a;}
    else if(b<=a && b<=c) {t=3;return b;}
    else {t=5;return c;}
}
struct node {
       int value;
       node *next;
       };
int main()
{
    int c=1,t;
    node *ptr2,*ptr3,*ptr5,*ugly,*temp;
    ugly=new node;ugly->value=1;ugly->next=NULL;
    ptr2=ptr3=ptr5=ugly;
    while(c<1500)
    {
     temp=new node;
     temp->value=min(2*(ptr2->value),3*(ptr3->value),5*(ptr5->value),t);
     if((ugly->value)<(temp->value)) 
     {ugly->next=temp;ugly=temp;ugly->next=NULL;c++;}
     else delete temp;
     switch (t)
     {
      case 2 : ptr2=ptr2->next;break;
      case 3 : ptr3=ptr3->next;break;
      case 5 : temp=ptr5;ptr5=ptr5->next;delete temp; break;
     }
    }
    cout<<"The 1500'th ugly number is "<<ugly->value<<".\n";
    return 0;
}
