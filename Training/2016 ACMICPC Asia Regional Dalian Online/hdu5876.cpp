#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int d[N];
vector<int>g[N][2];
queue<int>q[2];
int main()
{
    int _,n,m,s;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        int u,v,ok=1,k=0;
        for(int i=1; i<=n; i++)
        {
            d[i]=1;
            g[i][0].clear();
            g[i][1].clear();
        }
        ll ans=0;
        while(!q[0].empty()) q[0].pop();
        while(!q[1].empty()) q[1].pop();
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            g[u][k].push_back(v);
            g[v][k].push_back(u);
        }
        scanf("%d",&s);
        d[s]=0;
        for(int i=1; i<=n; i++)
        {
            if(g[i][k].size()==n-1)
            {
                ok=0;
                break;
            }
        }
        if(!ok)
        {
            puts("-1");
            continue;
        }
        for(int i=0; i<g[s][k].size(); i++)
        {
            u=g[s][k][i];
            d[u]++;
            q[k].push(u);
        }
        int cnt=n-1-g[s][k].size(),now=1,ncnt,nxt;
        while(!q[k].empty())
        {
            nxt=0;
            while(!q[k].empty())
            {
                u=q[k].front();
                q[k].pop();
                ncnt=0;
                g[u][k^1].clear();
                for(int i=0; i<g[u][k].size(); i++)
                {
                    v=g[u][k][i];
                    if(d[v]==now)
                        ncnt++;
                    else
                        g[u][k^1].push_back(v);
                }
                if(ncnt==cnt)
                {
                    d[u]++;
                    q[k^1].push(u);
                }
                else
                {
                    nxt++;
                }

            }
            k=k^1;
            cnt=nxt;
            now++;
        }
        for(int i=1; i<=n; i++)
        {
            ans+=(ll)d[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
1
6 5
6 1
6 2
6 3
6 5
4 5
6
*/
