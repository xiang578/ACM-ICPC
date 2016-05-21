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
char s[112345];
int a[112345],pre[123456];
int get(int l,int r)
{
    int t=pre[r];
    //printf("%d %d\n",t,a[l]);
    while(t%pre[l]!=0)
        t+=9973;
    return t/pre[l];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,l,r;
    while(~scanf("%d",&n))
    {
        scanf("%s",s);
        int len=strlen(s);
        pre[0]=1;
        for(int i=0;i<len;i++)
        {
            a[i+1]=s[i]-28;
            pre[i+1]=pre[i]*a[i+1]%9973;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",get(l-1,r)%9973);
        }
    }
    return 0;
}
