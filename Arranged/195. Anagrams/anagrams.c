#include<stdio.h>
int freq[200];
char a[100];
void printAnagrams(int start,int end)
{
 	 int i,t;
 	 if(start==end) {a[start]='\0';printf("%s\n",a);return;}
 	 for(i='A';i<='Z';i++) {
	 					   	t=i+32; 				    
                            if(freq[i]) {
		 								 freq[i]--;
   			 		   					 a[start]=i;
	 					    			 printAnagrams(start+1,end);
	 					    			 freq[i]++;
	 								    }
	 					    if(freq[t]) {
		 						 			  freq[t]--;
	 					    				  a[start]=t;
	 					    				  printAnagrams(start+1,end);
	 					    				  freq[t]++;
							}
     }
}
int main()
{
 	int N,i,l,j;
 	char w[100];
 	scanf("%d",&N);
 	for(i=0;i<N;i++) {
					  scanf("%s",w);
					  l=strlen(w);
					  for(j='A';j<='z';j++) freq[j]=0;
					  for(j=0;j<l;j++) freq[w[j]]++;
					  printAnagrams(0,l);
					 }
 	return 0;
}
