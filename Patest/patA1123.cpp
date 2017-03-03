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
int ok,rt,p[N];
struct node
{
    int num,l,r,h;
} a[N];

int get(int x)
{
    if(x==-1) return -1;
    else return a[x].h;
}

int in(int x,int now)
{
    if(now==-1)
    {
        now=x;
    }
    else if(a[x].num<a[now].num)
    {
        a[now].l=in(x,a[now].l);
        if(get(a[now].l)-get(a[now].r)==2)
        {
            if(a[x].num<a[a[now].l].num)//左旋
            {
                int A=now;
                int B=a[now].l;
                int BR=a[B].r;

                a[B].r=A;
                a[A].l=BR;
                a[A].h=max(get(a[A].l),get(a[A].r))+1;
                a[B].h=max(get(a[B].l),get(a[B].r))+1;
                now=B;
            }
            else
            {
                int A=now;
                int B=a[now].l;
                int C=a[B].r;
                int CL=a[C].l;
                int CR=a[C].r;

                now=C;
                a[C].l=B;
                a[C].r=A;
                a[B].r=CL;
                a[A].l=CR;

                a[A].h=max(get(a[A].l),get(a[A].r))+1;
                a[B].h=max(get(a[B].l),get(a[B].r))+1;
                a[C].h=max(get(a[C].l),get(a[C].r))+1;
            }
        }
    }
    else
    {
        a[now].r=in(x,a[now].r);
        if(get(a[now].r)-get(a[now].l)==2)
        {
            if(a[x].num>a[a[now].r].num)//右旋
            {
                int A=now;
                int B=a[now].r;
                int BL=a[B].l;

                a[B].l=A;
                a[A].r=BL;
                a[A].h=max(get(a[A].l),get(a[A].r))+1;
                a[B].h=max(get(a[B].l),get(a[B].r))+1;
                now=B;
            }
            else
            {
                int A=now;
                int B=a[now].r;
                int C=a[B].l;
                int CL=a[C].l;
                int CR=a[C].r;

                now=C;
                a[C].r=B;
                a[C].l=A;

                a[B].l=CR;
                a[A].r=CL;

                a[A].h=max(get(a[A].l),get(a[A].r))+1;
                a[B].h=max(get(a[B].l),get(a[B].r))+1;
                a[C].h=max(get(a[C].l),get(a[C].r))+1;
            }
        }
    }

    a[now].h=max(get(a[now].l),get(a[now].r))+1;
    return now;
}

void dfs(int x,int cnt)
{
    p[x]=cnt;
    if(a[x].l!=-1)
        dfs(a[x].l,cnt*2);
    if(a[x].r!=-1)
        dfs(a[x].r,cnt*2+1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,b,rt;
    cin>>n;
    if(n==0)
    {
        printf("YES\n");
        return 0;
    }
    for(int i=0; i<=n; i++)
    {
        a[i].num=a[i].l=a[i].r=-1;
        a[i].h=0;
    }
    rt=-1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].num;
        rt=in(i,rt);
    }
    vector<int>ans;
    ans.clear();
    queue<int>q;
    q.push(rt);
    ans.push_back(a[rt].num);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        if(a[t].l!=-1)
        {
            q.push(a[t].l);
            ans.push_back(a[a[t].l].num);
        }
        if(a[t].r!=-1)
        {
            q.push(a[t].r);
            ans.push_back(a[a[t].r].num);
        }
    }
    for(int i=0; i<ans.size(); i++)
    {
        if(i!=0) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    ok=1;
    memset(p,0,sizeof(p));
    dfs(rt,1);
    for(int i=1;i<=n;i++)
    {
        if(p[i]>n) ok=0;
    }
    if(ok==1) puts("YES");
    else puts("NO");
    return 0;
}
