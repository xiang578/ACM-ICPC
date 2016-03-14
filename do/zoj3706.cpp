#include<bits/stdc++.h>
using namespace std;

int g[1024][1024],a[1024];

int main()
{
    int _,n,m,u,v,cnt;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        cnt=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&u);
            v=a[i];
            if(u>v) swap(u,v);
            if(!g[u][v])
            {
                cnt++;
                g[u][v]=1;
            }
        }
        //printf("%d\n",cnt);
        printf("%.3f\n",1.0*cnt/n);
    }
    return 0;
}
