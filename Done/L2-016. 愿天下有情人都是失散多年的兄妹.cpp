#include<bits/stdc++.h>
using namespace std;
struct node
{
    int fa,ma;
    int f;
}p[100000+10];
int use[100000+10],ok;


void dfs1(int x,int t)
{
    if(t==-1) return ;
    use[x]=t;
    if(p[x].fa!=-1) dfs1(p[x].fa,t-1);
    if(p[x].ma!=-1) dfs1(p[x].ma,t-1);
}

void dfs2(int x,int t)
{
    if(t==-1) return ;
    if(use[x]==t) {ok=0;}
    if(p[x].fa!=-1) dfs2(p[x].fa,t-1);
    if(p[x].ma!=-1) dfs2(p[x].ma,t-1);
}

int main()
{
    int n,m,id,fa,ma,a1,a2;
    char s[1024];
    scanf("%d",&n);
    for(int i=0;i<100000+5;i++)
    {
        p[i].f=-1;
        p[i].fa=p[i].ma=-1;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d%s%d%d",&id,s,&fa,&ma);
        p[id].fa=fa;
        if(fa!=-1) p[fa].f=1;
        p[id].ma=ma;
        if(ma!=-1) p[ma].f=0;
        if(s[0]=='M') p[id].f=1;
        else p[id].f=0;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a1,&a2);
        if(p[a1].f==p[a2].f) printf("Never Mind\n");
        else
        {
            memset(use,0xff,sizeof(use));
            ok=1;
            dfs1(a1,4);
            dfs2(a2,4);
            if(ok) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
