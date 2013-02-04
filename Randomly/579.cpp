#include<iostream>
using namespace std;
int main()
{
    
    string time;
    float min = 0.00,hrs = 0.00;
    int i = 0;
    while(cin>>time && time != "0:00")
    {
    
                    while(time[i] != ':')
                    hrs = 10*hrs + (float)time[i++] - '0';i++;
                    while(time[i])
                     min = 10*min +(float)time[i++] - '0';
                    hrs = hrs*30 - min*5.50;
                    if(hrs<0) hrs = 0.00 - hrs;
                    if(hrs<=360-hrs)
                    printf("%.3f\n",hrs);
                    else
                    printf("%.3f\n",360 - hrs);
                    min = hrs = 0.00;
                    i = 0;
    }
    return 0;
}
