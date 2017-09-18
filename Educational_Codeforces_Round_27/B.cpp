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

int get(int a,int b,int c,int sum)
{
    int ret=3;
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                int now=i+j+k;
                int tmp=0;
                if(now==sum)
                {
                    if(i!=a) tmp++;
                    if(j!=b) tmp++;
                    if(k!=c) tmp++;
                    ret=min(ret,tmp);
                }
            }
        }
    }
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s;
    cin>>s;
    int ans = min(get(s[0]-'0',s[1]-'0',s[2]-'0',s[3]+s[4]+s[5]-3*'0'),get(s[3]-'0',s[4]-'0',s[5]-'0',s[0]+s[1]+s[2]-3*'0'));
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=9;k++)
            {
                int now=i+j+k;
                int tmp=0;
                if(i!=s[0]-'0') tmp++;
                if(j!=s[1]-'0') tmp++;
                if(k!=s[2]-'0') tmp++;
                ans=min(ans,tmp+get(s[3]-'0',s[4]-'0',s[5]-'0',now));
                tmp=0;
                if(i!=s[3]-'0') tmp++;
                if(j!=s[4]-'0') tmp++;
                if(k!=s[5]-'0') tmp++;
                ans=min(ans,tmp+get(s[0]-'0',s[1]-'0',s[2]-'0',now));
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
