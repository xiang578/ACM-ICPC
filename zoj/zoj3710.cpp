#include<bits/stdc++.h>
using namespace std;

int g[120][120];
vector<int>v[120];

int main()
{
    int i,n,m,k,j,ans,a,b,t,p,_,pre;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(g,0,sizeof(g));
        for(i=0; i<n; i++) v[i].clear();
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            if(!g[a][b])
            {
                g[a][b]=1;
                g[b][a]=1;
            }
        }
        ans=0,pre=0;
        int f=1;
        while(f)
        {
            pre=ans;
            for(i=0; i<n; i++)
            {
                for(j=i+1; j<n; j++)
                {
                    if(g[i][j]) continue;
                    t=0;
                    for(p=0; p<n; p++)
                    {
                        if(g[p][i]&&g[p][j]) t++;
                    }
                    if(t>=k)
                    {
                        ans+=1;
                        g[i][j]=g[j][i]=1;
                    }
                }
            }
            if(pre==ans) f=0;
            //printf("%d %d\n",ans,pre);
        }
        printf("%d\n",ans);
    }
    return 0;
}
