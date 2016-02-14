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

int a[300000+10];
int s[300000+10],e[300000+10];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,n,st,cnt;
    while(~scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        set<int>use;
        cnt=0;
        st=1;
        for(i=1;i<=n;i++)
        {
            if(use.find(a[i])!=use.end())
            {
                s[cnt]=st;
                e[cnt]=i;
                cnt++;
                st=i+1;
                use.clear();
            }
            else
            {
                use.insert(a[i]);
            }
        }
        if(cnt==0)
        {
            printf("-1\n");
        }
        else
        {
            e[cnt-1]=n;
            printf("%d\n",cnt);
            rep(i,0,cnt)
            {
                printf("%d %d\n",s[i],e[i]);
            }
        }
    }
    return 0;
}
