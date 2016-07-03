#include<bits/stdc++.h>
using namespace std;
const int N=100000+10;
int n,m,use[N],flag;
vector<int>g[N];
void dfs(int x,int k)
{
    int t;
    if(k==1) t=2;
    else t=1;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        if(use[y]==0)
        {
            use[y]=t;
            dfs(y,t);
        }
        else if(use[y]!=t)
            flag=0;
    }
}
int main()
{
    flag=1;
    int u,v;
    memset(use,0,sizeof(use));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        g[i].clear();
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
    {
        if(use[i]==0)
          dfs(i,1);
    }
    if(flag==0)
    {
        printf("-1\n");
    }
    else
    {
        vector<int>a;
        vector<int>b;
        for(int i=1;i<=n;i++)
        {
            if(use[i]==1)
                a.push_back(i);
            else if(use[i]==2)
                b.push_back(i);
        }
        printf("%d\n",a.size());
        for(int i=0;i<a.size();i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");

        printf("%d\n",b.size());
        for(int i=0;i<b.size();i++)
        {
            printf("%d ",b[i]);
        }
        printf("\n");
    }
    return 0;
}
