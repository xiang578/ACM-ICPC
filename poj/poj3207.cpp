#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;
const int N=1024;
int mark[2*N],s[2*N],c,n,m,st[N],ed[N];
vector<int>g[2*N];

int ok(int i,int j)
{
   if(ed[i]<st[j]||ed[j]<st[i]) return 1;
   if(st[i]<st[j]&&ed[j]<ed[i]) return 1;
   if(st[j]<st[i]&&ed[i]<ed[j]) return 1;
   return 0;
}
void init()
{
    for(int i=0;i<2*n;i++) g[i].clear();
    memset(mark,0,sizeof(mark));
}
void add(int x,int y)
{
    g[x].push_back(y);
}

int dfs(int x)
{
    if(mark[x^1]) return 0;
    if(mark[x]) return 1;
    mark[x]=1;
    s[c++]=x;
    for(int i=0;i<g[x].size();i++)
    {
        if(!dfs(g[x][i])) return 0;
    }
    return 1;
}
int solve()
{
    for(int i=0;i<2*n;i+=2)
    {
        if(!mark[i]&&!mark[i+1])
        {
            c=0;
            if(!dfs(i))
            {
                while(c>0)
                    mark[s[--c]]=0;
                if(!dfs(i+1))
                    return 0;
            }
        }
    }
    return 1;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&st[i],&ed[i]);
            if(st[i]>ed[i]) swap(st[i],ed[i]);
        }
        init();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(ok(i,j)==0)
                {
                    //printf("%d %d\n",i,j);
                    add(2*i,2*j+1);
                    add(2*j,2*i+1);
                    add(2*i+1,2*j);
                    add(2*j+1,2*i);
                }
            }
        }
        if(solve()==0) printf("the evil panda is lying again\n");
        else printf("panda is telling the truth...\n");
        //for(int i=0;i<2*n;i++)
          //  if(mark[i]) printf("%d\n",i);
    }
    return 0;
}
