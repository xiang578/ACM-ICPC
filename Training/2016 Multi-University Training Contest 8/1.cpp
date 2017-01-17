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

int a[N],b[N],n,m,u[N],cnt[N];
struct node
{
    int l,r;
}p[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        for(int i=1;i<=n;i++)
            scanf("%d",b+i);
        for(int i=0;i<m;i++)
            scanf("%d%d",&p[i].l,&p[i].r);
        memset(u,0,sizeof(u));
        int ok=1;
        for(int i=0;)
        if(ok) puts("Yes");
        else puts("No");
    }
    return 0;
}
/*int a[N],b[N],n,m,u[N],cnt[N];
struct node
{
    int l,r;
}p[N];

int cmp(node n1,node n2)
{
    if(n1.l==n2.l) return n1.r<n2.r;
    else return n1.l<n2.l;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        for(int i=1;i<=n;i++)
            scanf("%d",b+i);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&p[i].l,&p[i].r);
        }
        sort(p,p+m,cmp);
        memset(u,0,sizeof(u));
        int t=1;
        for(int i=0;i<m;i++)
        {
            if(i)
            {
                if(p[i].l>p[i-1].r) t++;
            }
            for(int j=p[i].l;j<=p[i].r;j++)
                u[j]=t;
        }
        int ok=1,up;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;)
        {
            if(u[i]==0)
            {
                if(a[i]!=b[i]) ok=0;
                i++;
            }
            else
            {
                up=0;
                for(int j=i;;j++)
                {
                    if(u[j]!=u[i]||j>n)
                    {
                        i=j;
                        break;
                    }
                    up=max(up,max(a[j],b[j]));
                    cnt[a[j]]++;
                    cnt[b[j]]--;
                }
                for(int j=0;j<=up;j++)
                {
                    if(cnt[j]!=0) ok=0;
                    cnt[j]=0;
                }
            }
            if(!ok) break;
        }
        if(ok) puts("Yes");
        else puts("No");
    }
    return 0;
}*/
