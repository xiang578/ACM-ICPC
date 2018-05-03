#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
    int u,v,w;
};
Edge g[100000+5];
int p[10000+5],n,m,in[10000+5];

int cmp(Edge a,Edge b)
{
    return a.w>b.w;
}

int Find(int x)
{
    if(x==p[x]) return x;
    return p[x]=Find(p[x]);
}

void Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
   if(fx!=fy) p[fx]=fy;
}

int main()
{
    int i,u,v,ans;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        for(i=0;i<n;i++)
            p[i]=i;
        for(i=0;i<m;i++)
            scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].w);
        memset(in,0,sizeof(in));
        sort(g,g+m,cmp);
        ans=0;
        for(i=0;i<m;i++)
        {
            u=g[i].u;
            v=g[i].v;
            u=Find(u);
            v=Find(v);
            if(u!=v)
            {
                if(!in[u]&&!in[v])
                {
                    Union(u,v);
                    ans+=g[i].w;
                }
                else if(!in[u]||!in[v])
                {
                    Union(u,v);
                    in[u]=in[v]=1;
                    ans+=g[i].w;
                }
            }
            else
            {
                if(!in[u]&&!in[v])
                {
                    in[u]=in[v]=1;
                    ans+=g[i].w;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
