/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
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
const int M=1e6+10;
const ll inf=1e18;
ll mp[200][200];
vector<ll>v;
ll a,ans,t,x,d,f;
string s;

int ok(ll now,ll p,int st)
{
    for(int i=st; i>=0; i--)
    {
        now=now+(s[i]-'0')*p;
        p*=10;
        if(p>10*a) return 0;
        if(s[i]=='0') continue;
        if(now<a) return 1;
        if(now>=a) return 0;
    }
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(cin>>a)
    {
        cin>>s;
        v.clear();
        t=0;
        ans=0;
        x=1;
        d=1;
        for(int i=s.size()-1; i>=0; i--)
        {
            //printf("****%lld\n",t);
            if(s[i]=='0'&&ok(t,d,i)==0)
            {
                if(t!=0) v.push_back(t);
                t=0;
                d=10;
                if(ok(0,1,i)==0)
                {
                    //printf("*******\n");
                    v.push_back(0);
                    d=1;
                }
            }
            else
            {
                ll n=d*(s[i]-'0')+t;
                if(n>=a)
                {
                    v.push_back(t);
                    t=s[i]-'0';
                    d=1;
                }
                else
                {
                    t=n;
                }
                d*=10;
            }
        }
        if(t!=0) v.push_back(t);
        x=1;
        ans=0;
        for(int i=0; i<v.size(); i++)
        {
            //printf("%lld %lld\n",v[i],x);
            ans+=x*v[i];
            x*=a;
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
//题面要找最小的
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll a,ans,t,x,d,f;
    string s;
    while(cin>>a)
    {
        v.clear();
        cin>>s;
        t=0;
        d=1;
        f=0;
        for(int i=0;i<s.size();i++)
        {
            if(t==0&&s[i]=='0')
            {
                v.push_back(0);
                continue;
            }
            ll n=t*10+s[i]-'0';
            if(n>a)
            {
                v.push_back(t);
                if(s[i]=='0') v.push_back(0);
                t=s[i]-'0';
            }
            else
            {
                t=n;
            }
        }
        //printf("%lld %lld\n",t,x);
        if(t!=0) v.push_back(t);
        ans=0,x=1;
        for(int i=v.size()-1;i>=0;i--)
        {
            printf("%lld %lld\n",v[i],x);
            ans+=x*v[i];
            x*=a;
        }
        cout<<ans<<endl;
    }
    return 0;
}*/

/*
//从最后以为开始贪心，前导零这部分出现了错误
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll a,ans,t,x,d,f;
    string s;
    while(cin>>a)
    {
        cin>>s;
        t=0;
        ans=0;
        x=1;
        d=1;
        f=0
        for(int i=s.size()-1;i>=0;i--)
        {

            ll n=d*(s[i]-'0')+t;
            if(s[i]=='0') f
            if(n>a)
            {
                ans+=t*x;
                t=s[i]-'0';
                d=1;
                x=x*a;
            }
            else
            {
                t=n;
            }
            d*=10;
            printf("%lld %lld\n",t,x);
        }
        //printf("%lld %lld\n",t,x);
        ans+=t*x;
        cout<<ans<<endl;
    }
    return 0;
}
*/
