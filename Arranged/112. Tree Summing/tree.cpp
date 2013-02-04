#include<iostream>
#define MAX 10000
using namespace std;
bool exist_sum(int S,char * T,int st,int e,int * index)
{
    int i=st+1,v=0,s=1;
    if(e==i) return false;
    if(T[i]=='-') {s=-1;i++;}
    while(T[i]!='(') {v=v*10+T[i]-'0';i++;}
    //cout<<S<<" "<<v<<endl;
    if(T[e-4]=='(' && T[e-3]==')' && T[e-2]=='(' && T[e-1]==')') {
                                                                   if(S==(s*v)) return true; else return false;
                                                                 }
    //exist_sum(S,T,i,index[i],index);
    //exist_sum(S,T,index[i]+1,index[index[i]+1],index);
    return (exist_sum(S-s*v,T,i,index[i],index) || exist_sum(S-s*v,T,index[i]+1,index[index[i]+1],index));
    return true;
}
int main()
{
    int sp,i,j,n,l,index[MAX],stack[MAX],sg;
    char c=' ',expression[MAX],flag=0;
    while(true)
    {
       n=0;sp=-1;i=0;sg=1;
       while(c==' ' || c=='\n') c=getchar();
       if(c==EOF) break;
       else if(c=='-') sg=-1;
       else n=n*10+(c-'0');
       while((c=getchar())>='0' && c<='9') n=n*10+c-'0';
       n=sg*n;
       while((c=getchar())!='(');
       ++sp;expression[i++]='(';
       while(sp!=-1) {
           c=getchar();
           if(c=='(') ++sp; else if(c==')') --sp;
           if(c!=' ' && c!='\n') expression[i++]=c;
       }
       expression[i]='\0';l=i;j=0;i--;
       if(l==2) cout<<"no\n"; else {
       while(j<i) { if(expression[j]=='(' && expression[i]==')') {index[j]=i;j++;i--;}
                    else if(expression[j]!='(') j++;
                    else i--;
       }
       for(j=0;j<l;j++) {
           if(expression[j]=='(') stack[++sp]=j;
           else if(expression[j]==')') {index[stack[sp]]=j;sp--;}
       }
       //cout<<n<<" "<<expression<<endl;
       if(exist_sum(n,expression,0,index[0],index)) cout<<"yes"<<endl; else cout<<"no"<<endl;
       }
       while(c!='\n' && c!=EOF) c=getchar();if(c==EOF) break;
    }
    return 0;
}
