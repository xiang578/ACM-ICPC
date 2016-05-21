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
const int N=60;
int n,m,ans;
map<string,int>mp;
vector<string>v[10];

void dfs(string a,int cnt)
{
    if(cnt==n)
    {
        if(mp[a]==0)
        {
            mp[a]++;
            ans++;
        }
        return ;
    }
    else
    {
        string b;
        int t=a[0]-'a';
        for(int k=0; k<v[t].size(); k++)
        {
            b=v[t][k]+a.substr(1,a.size());
            dfs(b,cnt+1);
        }
    }

}

int main()
{
    string s1,s2;
    mp.clear();
    scanf("%d%d",&n,&m);
    for(int i=0; i<10; i++)
        v[i].clear();

    for(int i=0; i<m; i++)
    {
        cin>>s1>>s2;
        int t=s2[0]-'a';
        v[t].push_back(s1);
    }
    ans=0;
    s1="a";
    dfs(s1,1);
    printf("%d\n",ans);
    return 0;
}
