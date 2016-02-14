/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=2048;


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,j,n,f,d1,d2,d3;
    ll a,b,ans;
    char s[20];
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        scanf("%lld%lld",&a,&b);
        ans=0;
        for(i=0;i<n;i++)
        {
            f=0;
            scanf("%s",s);
            for(j=0;j<11;j++)
                s[j]=s[j]-'0';
            for(j=6;j<10;j++)
                if(s[j]!=s[j+1]) break;
            if(j==10) f=1;
            for(j=6;j<10;j++)
                if(s[j]!=s[j+1]+1) break;
            if(j==10) f=1;
            for(j=6;j<10;j++)
                if(s[j]!=s[j+1]-1) break;

            if(j==10) f=1;
            d2=s[7]*10+s[8];
            d3=s[9]*10+s[10];
            d1=s[3]*1000+s[4]*100+s[5]*10+s[6];
            if(d1<=2016&&d1>=1980)
            {
               if(d2>=1&&d2<=12)
               {
                   if(d3>=1&&d3<=28) f=1;
                   else if(d3==29)
                   {
                       if(d2==2&&d1%4==0) f=1;
                       if(d2!=2) f=1;
                   }
                   else if(d3==30)
                   {
                       if(d2!=2) f=1;
                   }
                   else if(d3==31)
                   {
                       if(d2==1||d2==3||d2==5||d2==7||d2
                          ==8||d2==10||d2==12)
                            f=1;
                   }
               }
            }
            if(f==1) ans+=a;
            else ans+=b;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
