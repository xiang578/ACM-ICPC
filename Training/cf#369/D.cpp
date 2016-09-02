#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*1e5+10;
const int mod=1e9+7;
int dfn[N],def,cnt,vis[N];
vector<int>g[N];
vector<int>d;
int fs;
void dfs(int u,int fa,int dep)
{
    if(vis[u]!=0)
    {
        if(fs==0)
        d.push_back(dep-vis[u]);
        fs=1;
        return ;
    }
    int f=0;
    vis[u]=dep;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(f==0&&v==fa)
        {
            f++;
            continue;
        }
        dfs(v,u,dep+1);
    }
}

ll fst(int x)
{
    ll ret=1,p=2;
    while(x)
    {

        if(x&1)
            ret=(ret*p)%mod;
        p=(p*p)%mod;
        x>>=1;
    }
    return ret;
}

int main()
{
    int n,j,k;
    scanf("%d",&n);
    ll ans=1;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&j);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    d.clear();
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
        if(!vis[i])
            {
                fs=0;
                dfs(i,-1,1);
            }
    k=0;
    //printf("%d\n",d.size());
    for(int i=0;i<d.size();i++)
    {
        //printf("%d %d\n",i,d[i]);
        ans=ans*(fst(d[i])-2+mod)%mod;
        k+=d[i];
    }
    //printf("1111");
    ans=ans*(fst(n-k))%mod;
    printf("%lld\n",ans);
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*1e5+10;
const int mod=1e9+7;
int dfn[N],def,cnt,low[N],ins[N],id[N],sum[N];
vector<int>g[N];
stack<int>st;
void tarjan(int u)
{
    int v;
    dfn[u]=low[u]=++def;
    ins[u]=1;
    st.push(u);
    for(int i=0; i<g[u].size(); i++)
    {
        v=g[u][i];
        //if(v==fa) continue;
        if(!dfn[v])
        {
            tarjan(v);
            if(low[v]<low[u])
                low[u]=low[v];
        }
        else if(ins[v]&&dfn[v]<low[u])
        {
            low[u]=dfn[v];
        }
    }
    if(dfn[u]==low[u])
    {
        cnt++;
        sum[cnt]=0;
        do
        {
            v=st.top();
            st.pop();
            ins[v]=0;
            id[v]=cnt;
            sum[cnt]++;
        }
        while(u!=v);
    }
}

ll fst(int x)
{
    ll ret=1,p=2;
    while(x)
    {

        if(x&1)
            ret=(ret*p)%mod;
        p=(p*p)%mod;
        x>>=1;
    }
    return ret;
}

int main()
{
    int n,j,k;
    scanf("%d",&n);
    ll ans=1;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&j);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    cnt=def=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(ins,0,sizeof(ins));
    while(!st.empty()) st.pop();
    for(int i=1; i<=n; i++)
        if(!dfn[i])
            tarjan(i);
    k=0;
    for(int i=1;i<=cnt;i++)
    {
        printf("%d %d\n",i,sum[i]);
        if(sum[i]==1) k++;
        else ans=ans*(fst(sum[i])-2+mod)%mod;
    }
    ans=ans*(fst(k))%mod;
    printf("%lld",(ans+mod)%mod);
    return 0;
}
*/
