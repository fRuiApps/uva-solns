#include<iostream>
#include<vector>
#include<stack>
#define SPACES(k) for(int x=0;x<k;x++) cout<<" ";
using namespace std;
vector<char> seq;
stack<char> vars;
void writeProgram(int space)
{
     int lt;
     //for(int i=0;i<seq.size()-1;i++) cout<<seq[i]<<",";cout<<seq[seq.size()-1]<<")\n";
     if(vars.empty()) {
                       SPACES(space);
                       cout<<"writeln(";
                       for(int i=0;i<seq.size()-1;i++) cout<<seq[i]<<",";cout<<seq[seq.size()-1]<<")\n";
     }
     else {
           char t=vars.top(),temp;
           vars.pop();
           seq.push_back(t);
           lt=seq.size()-1;
           SPACES(space);
           cout<<"if "<<seq[lt-1]<<" < "<<seq[lt]<<" then\n";
           writeProgram(space+3);
           temp=seq[lt];seq[lt]=seq[lt-1];seq[lt-1]=temp;lt--;
           for(;lt;lt--) {
                          SPACES(space);
                          cout<<"else if "<<seq[lt-1]<<" < "<<seq[lt]<<" then\n";
                          writeProgram(space+3);
                          temp=seq[lt];seq[lt]=seq[lt-1];seq[lt-1]=temp;
                         }
           SPACES(space);cout<<"else\n";writeProgram(space+3);
           temp=*(seq.begin());
           seq.erase(seq.begin());
           vars.push(temp);
          }
     
}
int main()
{
    int M,i,j,n;
    bool flag=false;
    cin>>M;
    for(i=0;i<M;i++) {
                      cin>>n;
                      seq.clear();while(!vars.empty()) vars.pop();
                      if(flag) cout<<endl; else flag=true;
                      for(j=n-1;j>=0;j--) vars.push('a'+j);
                      cout<<"program sort(input,output);\n";
                      cout<<"var\n";
                      for(j=0;j<n-1;j++) cout<<char('a'+j)<<',';cout<<char('a'+n-1)<<" : integer;\n";
                      cout<<"begin\n";
                      SPACES(3);cout<<"readln(";for(j=0;j<n-1;j++) cout<<char('a'+j)<<',';cout<<char('a'+n-1)<<");\n";
                      seq.push_back('a');
                      vars.pop();
                      writeProgram(3);
                      cout<<"end.\n";                 
                     }
    return 0;
}
