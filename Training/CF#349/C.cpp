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
char s[100000+10];
int dp[10000+10][5];
map<string,int>mp;
vector<string>v;
int len;

int get(int st,int l)
{
    string t1,t2,t3;
    if(st+l>len)
        return 0;
    else if(st+l==len)
    {
        for(int i=0; i<l; i++)
            t1+=s[st+i];
        if(mp[t1]==0)
        {
            mp[t1]++;
            v.push_back(t1);
        }
    }
    else
    {
        int f=0,s2=st+l;
        for(int i=0; i<l; i++)
            t1+=s[st+i];
        for(int i=0;i<2;i++)
            t2+=s[s2+i];
        for(int i=0;i<3;i++)
            t3+=s[s2+i];
       if(l==2)
       {
           if(t1!=t2&&dp[s2][2]) f=1;
           if(dp[s2][3]) f=1;
       }
       else if(l==3)
       {
           if(t1!=t3&&dp[s2][3]) f=1;
           if(dp[s2][2]) f=1;
       }
        if(f==0) return 0;
        if(mp[t1]==0)
        {
            mp[t1]++;
            v.push_back(t1);
        }
    }
    return 1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(s,0,sizeof(s));
    scanf("%s",s);
    v.clear();
    mp.clear();
    memset(dp,0,sizeof(dp));
    len=strlen(s);
    for(int i=len-1; i>=5; i--)
    {
        dp[i][2]=get(i,2);
        dp[i][3]=get(i,3);
    }
    sort(v.begin(),v.end());
    printf("%d\n",v.size());
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}
