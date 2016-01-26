#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=100005;
char t[20];
int get(char a[20])
{
    int i,j;
    for(i=6;i<=10;i++)
        if(a[i]==a[6]) continue;
    else break;
    if(i>10) return 1;
    for(i=7;i<=10;i++) if(a[i]==a[i-1]+1) continue; else break;
    if(i>10) return 1;
    for(i=7;i<=10;i++) if(a[i]==a[i-1]-1) continue; else break;
    if(i>10) return 1;
    int year=0,mo=0,day=0;
    for(i=3;i<=6;i++) year*=10,year+=a[i]-'0';
    for(i=7;i<=8;i++) mo*=10,mo+=a[i]-'0';
    for(i=9;i<=10;i++) day*=10,day+=a[i]-'0';
    if(year>=1980&&year<=2016)
    {
        if(mo>=1&&mo<=12)
        {
            if(day>=1&&day<=31)
            {
                if(day<=28) return 1;
                if(mo==2&&day==29&&year%4==0) return 1;
                if(mo==2&&day>29) return 0;
                if(day==31)
                {
                    if(mo==1||mo==3||mo==5||mo==7||mo==8||mo==10||mo==12) return 1;
                }

            }
        }
    }
    return 0;
}
int x,y,n;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
    /*while(scanf("%d",&n)!=EOF)
    {*/
    scanf("%d",&n);
    scanf("%d%d",&x,&y);
    long long ans=0;
    while(n--)
    {
        scanf("%s",t);
        int tp=get(t);
        if(tp) ans+=x;
        else ans+=y;
    }
    cout<<ans<<endl;
    }
    return 0;
}
