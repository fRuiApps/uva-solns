#include<iostream>
using namespace std;
struct node {int val;int freq;node *next;};
int main()
{
    node *first,*temp,*last;
    int n;
    first=new node;last=first;first->next=NULL;
    while(cin>>n)
    {
     temp=first->next;
     while(temp!=NULL) { if((temp->val)==n) {(temp->freq)++;break;} temp=temp->next;}
     if(temp==NULL) {temp=new node;(temp->val)=n;(temp->freq)=1;last->next=temp;last=temp;last->next=NULL;}
    }
    temp=first->next;
    while(temp!=NULL)
    {
     cout<<temp->val<<" "<<temp->freq<<endl;
     temp=temp->next;
    }
    return 0;
}
