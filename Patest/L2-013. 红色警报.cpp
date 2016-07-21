#include<bits/stdc++.h>
using namespace std;
const int N=500+10;
const int M=5000+10;

struct edge
{
    int u,v,f;
};
edge e[M];
vector<int>g[N];
int n,m,use[N],last,now,del[N],cnt[N],be[N];

void dfs(int x,int tt)
{
    be[N]=tt;
    cnt[now]++;
    use[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int j=g[x][i];
        if(e[j].f==0) continue;
        if(e[j].u==x&&use[e[j].v]==0) dfs(e[j].v,tt);
        else if(use[e[j].u]==0) dfs(e[j].u,tt);
    }
}

int main()
{
    int u,v,t,x;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++) g[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&e[i].u,&e[i].v);
            e[i].f=1;
            g[e[i].u].push_back(i);
            g[e[i].v].push_back(i);
        }
        memset(use,0,sizeof(use));
        memset(cnt,0,sizeof(cnt));
        last=0;
        for(int i=0;i<n;i++)
        {
            if(use[i]==0)
            {
                last++;
                dfs(i,last);
            }
        }
        //printf("%d\n",last);
        scanf("%d",&t);
        memset(del,0,sizeof(del));
        for(int i=0;i<t;i++)
        {
            scanf("%d",&x);
            del[x]=1;
            int old=cnt[be[i]];
            memset(use,0,sizeof(use));
            memset(cnt,0,sizeof(cnt));
            now=0;
            for(int j=0;j<m;j++)
            {
                if(e[j].u==x||e[j].v==x)
                    e[j].f=0;
            }
            for(int j=0;j<n;j++)
            {
                if(use[j]==0&&!del[j])
                {
                    now++;
                    dfs(j,now);
                }
            }
            if(now>last) printf("Red Alert: City %d is lost!\n",x);
            else printf("City %d is lost.\n",x);
            if(now==0) puts("Game Over.");
            last=now;
        }
    }
    return 0;
}
