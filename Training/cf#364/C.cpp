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
const int N=1e5+10;
char s[N];
int ans,a[200],cnt,mx;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    memset(a,0,sizeof(a));
    ans=n;
    mx=0;
    for(int i=0;i<n;i++)
    {
        if(a[s[i]]==0)
        {
            mx++;
            a[s[i]]=1;
        }
    }
    memset(a,0,sizeof(a));
    cnt=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(cnt!=mx&&j<n)
        {
            if(a[s[j]]==0)
            {
                cnt++;
            }
            a[s[j]]++;
            j++;
        }
        if(cnt==mx) ans=min(ans,j-i);
        //if(j>=n) break;
        a[s[i]]--;
        if(a[s[i]]==0) cnt--;
    }
    cout<<ans;
    return 0;
}
