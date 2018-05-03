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
const int N=1e7+1;
int n,k,tot;
int ch[N][2];
int v[N];

int get(int t)
{
    int x,u=1;
    for(int i=31; i>=0; i--)
    {
        x=(t>>i)&1^1;
        if(ch[u][x])
            u=ch[u][x];
        else
            u=ch[u][x^1];
    }
    return v[u];
}

void add(int t)
{
    int u=1;
    for(int i=31; i>=0; i--)
    {
        int p=(t>>i)&1;
        if(ch[u][p]==0)
        {
            ch[u][p]=tot;
            tot++;
        }
        if(!v[u]) v[u]++;
        u=ch[u][p];
    }
    v[u]=t;
}

int main()
{

    int t,_;
    scanf("%d",&_);
    for(int __=1;__<=_;__++)
    {
        scanf("%d%d",&n,&k);
        tot=2;
        memset(ch,0,sizeof(ch));
        memset(v,0,sizeof(v));
        //add(0);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&t);
            add(t);
        }
        printf("Case #%d:\n",__);
        for(int i=0;i<k;i++)
        {
            scanf("%d",&t);
            printf("%d\n",get(t));
        }
    }
    return 0;
}
