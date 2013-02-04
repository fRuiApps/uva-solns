#include<iostream>
#include<string>
using namespace std;
int toNumber(string words[],int st,int end,int mil,int thou)
{
    int i,n=0;
    if(mil!=-1)
        return toNumber(words,st,mil-1,-1,-1)*1000000+toNumber(words,mil+1,end,-1,thou);
    else if(thou!=-1)
        return toNumber(words,st,thou-1,-1,-1)*1000+toNumber(words,thou+1,end,-1,-1);
    for(i=st;i<=end;i++) {
    if(words[i]=="zero") n+=0;
    else if(words[i]=="one") n+=1;
    else if(words[i]=="two") n+=2;
    else if(words[i]=="three") n+=3;
    else if(words[i]=="four") n+=4;
    else if(words[i]=="five") n+=5;
    else if(words[i]=="six") n+=6;
    else if(words[i]=="seven") n+=7;
    else if(words[i]=="eight") n+=8;
    else if(words[i]=="nine") n+=9;
    else if(words[i]=="ten") n+=10;
    else if(words[i]=="eleven") n+=11;
    else if(words[i]=="twelve") n+=12;
    else if(words[i]=="thirteen") n+=13;
    else if(words[i]=="fourteen") n+=14;
    else if(words[i]=="fifteen") n+=15;
    else if(words[i]=="sixteen") n+=16;
    else if(words[i]=="seventeen") n+=17;
    else if(words[i]=="eighteen") n+=18;
    else if(words[i]=="nineteen") n+=19;
    else if(words[i]=="twenty") n+=20;
    else if(words[i]=="thirty") n+=30;
    else if(words[i]=="forty") n+=40;
    else if(words[i]=="fifty") n+=50;
    else if(words[i]=="sixty") n+=60;
    else if(words[i]=="seventy") n+=70;
    else if(words[i]=="eighty") n+=80;
    else if(words[i]=="ninety") n+=90;
    else if(words[i]=="hundred") n*=100;
    }
    return n;
}
int main()
{
    string s,t,words[20];
    char temp[10];
    int n,i,l,j=0,k,sign,million,thousand;
    while(getline(cin,s)) {
    l=s.length();sign=1;k=0;million=-1;thousand=-1;
    for(i=0;i<=l;i++) {
                       if(s[i]==' '||s[i]=='\0') {
                                                 temp[j]='\0';j=0;
                                                 t=temp;
                                                 if(k==0 && t=="negative")
                                                    sign=-1;
                                                 else
                                                    words[k++]=t;
                                                 if(t=="million") million=k-1;
                                                 if(t=="thousand") thousand=k-1;
                                                }
                      else temp[j++]=s[i];
    }
    n=toNumber(words,0,k-1,million,thousand);
    n*=sign;
    cout<<n<<endl;
    }
    return 0;
}
