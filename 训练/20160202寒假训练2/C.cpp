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

int a[100000+10][10];
char s[100000+10];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j,len,n,m,t;
    ll b1,b2;
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%s",s);
        memset(a,0,sizeof(a));
        len=strlen(s);
        for(i=1;i<=len;i++)
        {
            for(j=0;j<=9;j++)
                a[i][j]=a[i-1][j];
            s[i-1]=s[i-1]-'0';
            t=s[i-1];
            a[i][t]++;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&t);
            b1=b2=0;
            for(j=s[t-1];j<=9;j++)
                b2+=(j-s[t-1])*a[t][j];
            for(j=0;j<=s[t-1];j++)
                b1+=(s[t-1]-j)*a[t][j];
            if(b1>b2) puts("Keep some distance from me");
            else if(b1==b2) puts("Next time");
            else puts("I agree");
        }
    }
    return 0;
}
