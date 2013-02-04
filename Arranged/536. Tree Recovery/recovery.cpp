#include<iostream>
#include<cstring>
using namespace std;
void postOrder(char * inOrder,char * preOrder, int ist,int ien,int pst,int pen)
{
 	 int i,j,k;
 	 bool occured[26]={false};
 	 char A;
 	 A=preOrder[pst];
 	 if(ien==ist) 
 	 {
      cout<<inOrder[ist];
     }
     else
     {
 	  for(i=ist;inOrder[i]!=A;i++) occured[inOrder[i]-'A']=true;j=i;
 	  for(i=pst+1;occured[preOrder[i]-'A'];i++); k=i;
 	  if((j-1)>=ist && (k-1)>=(pst+1)) postOrder(inOrder,preOrder,ist,j-1,pst+1,k-1);
 	  if(ien>=(j+1) && pen>=k) postOrder(inOrder,preOrder,j+1,ien,k,pen);
 	  cout<<A;
	 }
}
int main()
{
 	 char inOrder[30],preOrder[30];
 	 int l;
 	 while(cin>>preOrder>>inOrder) {
	 							   l=strlen(preOrder);
	 							   postOrder(inOrder,preOrder,0,l-1,0,l-1);
	 							   cout<<endl;
	 							  }
	 return 0;
}
