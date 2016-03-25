#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[60][60],in[100],n,m;

void dfs(int t)
{
    int i;
    for(i=1; i<=50; i++)
        if(g[t][i])
        {
            g[t][i]--;
            g[i][t]--;
            dfs(i);
            printf("%d %d\n",i,t);
        }
}

int main()
{
    int _,i,j,u,v,cnt,cas=0;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        memset(in,0,sizeof(in));
        memset(g,0,sizeof(g));
        m=0;
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            in[u]++;
            in[v]++;
            g[u][v]++;
            g[v][u]++;
        }
        for(i=1,cnt=0; i<=50; i++)
            if(in[i]%2==1)
                cnt++;
        printf("Case #%d\n",++cas);
        if(cnt!=0) printf("some beads may be lost\n");
        else
            for(i=1;i<=50;i++)
                dfs(i);
        if(_) printf("\n");
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Edge
{
  int u,v,use;
}g[1024];
int in[100],n;

void dfs(int t,int cnt)
{
    if(cnt==n) return ;
    int i,u,v;
    for(i=0;i<n;i++)
    {
        if(g[i].use==1) continue;
        u=g[i].u;
        v=g[i].v;
        if(u==t) break;
        if(v==t)
        {
            swap(u,v);
            break;
        }
    }
    g[i].use=1;
    printf("%d %d\n",u,v);
    dfs(v,cnt+1);
}

int main()
{
    int _,i,cnt,m,cas=0;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        memset(in,0,sizeof(in));
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&g[i].u,&g[i].v);
            g[i].use=0;
            in[g[i].u]++;
            in[g[i].v]++;
        }
        for(i=1,cnt=0;i<=50;i++)
            if(in[i]%2==1)
                cnt++;
        printf("Case #%d\n",++cas);
        if(cnt!=0) printf("some beads may be lost\n");
        else
        {
            printf("%d %d\n",g[0].u,g[0].v);
            g[0].use=1;
            dfs(g[0].v,1);
        }
        if(_) printf("\n");
    }
    return 0;
}
*/
