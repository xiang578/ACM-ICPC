#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node
{
    int to;
    ll w;
};
vector<node>g[N];
int n,st,ed,u[N],v[N],fa[N],use[N];
ll mx,d1[N],d2[N],dep[N];

void dfs(int x,ll d,int f)
{
	//printf("%d\n",x);
	if(d>mx)
	{
		ed=x;
		mx=d;
	}
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i].to;
		ll w=g[x][i].w;
		if(y==f) continue;
		dfs(y,d+w,x);
	}
}

void dfs1(int x,int f,ll o)
{
	ll m1=0,m2=0;
	fa[x]=f;
	d1[x]=0;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i].to;
		ll w=g[x][i].w;
		if(y==f) continue;
		dfs1(y,x,w);
		if(dep[y]>m1)
		{
			m2=m1;
			m1=dep[y];
		}
		else if(dep[y]>m2)
		{
			m2=dep[y];
		}
		d1[x]=max(d1[x],d1[y]);
	}
	d1[x]=max(d1[x],m1+m2);
	dep[x]=o+m1;
}

int dfs2(int x,int f,ll o)
{
	ll m1=0,m2=0;
	d2[x]=0;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i].to;
		ll w=g[x][i].w;
		if(y==f) continue;
		use[x]=max(use[x],dfs2(y,x,w));
		if(dep[y]>m1)
		{
			m2=m1;
			m1=dep[y];
		}
		else if(dep[y]>m2)
		{
			m2=dep[y];
		}
		d2[x]=max(d2[x],d2[y]);
	}
	d2[x]=max(m1+m2,d2[x]);
	dep[x]=o+m1;
	return use[x];
}

int main()
{
    int _;
    ll w;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        	g[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%lld",&u[i],&v[i],&w);
            node t;
            t.to=v[i];
            t.w=w;
            g[u[i]].push_back(t);

            t.to=u[i];
            g[v[i]].push_back(t);
        }
        mx=0;
        ed=1;
        dfs(1,0,0);
        st=ed;
        mx=0;
        dfs(st,0,0);

        memset(dep,0,sizeof(dep));
		dfs1(st,0,0);

		memset(dep,0,sizeof(dep));
		memset(use,0,sizeof(use));
		use[st]=1;
        dfs2(ed,0,0);

        ll ans=0;
        for(int i=1;i<n;i++)
        {
        	if(use[u[i]]!=1||use[v[i]]!=1)
        	{
        		ans+=mx;
			}
			else if(fa[u[i]]==v[i])
			{

				ans+=max(d2[v[i]],d1[u[i]]);
			}
			else
			{
				ans+=max(d1[v[i]],d2[u[i]]);
			}
		}
		printf("%lld\n",ans);
    }
    return 0;
}
