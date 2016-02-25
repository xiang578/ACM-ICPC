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
char s[412345];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,tp;
    ll ans;
    while(~scanf("%s",s))
    {
        int len=strlen(s);
        ans=0;
        for(i=len-1;i>=0;i--)
        {
            tp=s[i]-'0';
            if(tp%4==0) ans++;
            if(i>=1) tp=(s[i-1]-'0')*10+(s[i]-'0');
            else break;
            if(tp%4==0) ans+=i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
