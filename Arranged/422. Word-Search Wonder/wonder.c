#include<stdio.h>
char MAT[110][110];
int L;
int end(int x,int y,char *word,int s,int e,int dir1,int dir2)
{
 	if(x<0 || y<0 || x>L || y>L) return -1;
 	if(s==e) 
	{
     if(MAT[x][y]==word[s]) return (x*1000+y); else return -1;
 	}
 	else
 	{
 	 if(MAT[x][y]!=word[s]) return -1;
 	 else return end(x+dir1,y+dir2,word,s+1,e,dir1,dir2);
	}
}
int main()
{
     int i,t,j,l,flag;
     char word[110];
	 scanf("%d",&L);
	 L--;
	 for(i=0;i<=L;i++) scanf("%s",MAT[i]);
	 while(1) {
	 		   scanf("%s",word);if(strcmp(word,"0")==0) break;
			   flag=0;l=strlen(word)-1;
	 		   for(i=0;i<=L;i++) {
			   					  for(j=0;j<=L;j++) {
								  					 t=end(i,j,word,0,l,0,1);
				  					  				 if(t>0) {printf("%d,%d %d,%d\n",i+1,j+1,t/1000+1,t%1000+1);flag=1;break;}
													 t=end(i,j,word,0,l,1,1);
													 if(t>0) {printf("%d,%d %d,%d\n",i+1,j+1,t/1000+1,t%1000+1);flag=1;break;}
													 t=end(i,j,word,0,l,1,0);
													 if(t>0) {printf("%d,%d %d,%d\n",i+1,j+1,t/1000+1,t%1000+1);flag=1;break;}
													 t=end(i,j,word,0,l,1,-1);
													 if(t>0) {printf("%d,%d %d,%d\n",i+1,j+1,t/1000+1,t%1000+1);flag=1;break;}
													 t=end(i,j,word,0,l,0,-1);
													 if(t>0) {printf("%d,%d %d,%d\n",i+1,j+1,t/1000+1,t%1000+1);flag=1;break;}
													 t=end(i,j,word,0,l,-1,-1);
													 if(t>0) {printf("%d,%d %d,%d\n",i+1,j+1,t/1000+1,t%1000+1);flag=1;break;}
													 t=end(i,j,word,0,l,-1,0);
													 if(t>0) {printf("%d,%d %d,%d\n",i+1,j+1,t/1000+1,t%1000+1);flag=1;break;}
												 }
								 if(flag==1) break;
						 }
			   if(i==(L+1)) printf("Not Found\n"); 
	 		  } 	
	 return 0;
}
