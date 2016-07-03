//25组   组员：  14计算机2项闰冶140104200230 14计算机1陈勇 140104200104
//				15软工江昱竹140104400109 沈慧琴140104400117
//
/*
1003. Emergency (25)
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/
//解题思路：最短路变形题，最后从终点dfs就可以找出长度相同的方案数了
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int inf=0x3fffffff;

struct node
{
    int to,w;
};

int c1,c2,n,m,ans;
int a[1024],d1[1024],vis[1024],d2[1024],inq[1024];
vector<node>g[1024];
void dfs(int x)
{
    if(x==c1)
    {
        ans++;
        return ;
    }
    for(int i=0;i<g[x].size();i++)
    {
        int u=g[x][i].to;
        int w=g[x][i].w;
        if(d1[u]+w==d1[x])
        {
            dfs(u);
        }
    }
}
void spfa()
{
    for(int i=0;i<n;i++)
    {
        d1[i]=inf;
        d2[i]=0;
        inq[i]=0;
    }
    queue<int>q;
    q.push(c1);
    d1[c1]=0;
    d2[c1]=a[c1];
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        inq[u]=0;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].to;
            int w=g[u][i].w;
            if(d1[v]>d1[u]+w)
            {
                d1[v]=d1[u]+w;
                d2[v]=d2[u]+a[v];
                if(inq[v]==0)
                {
                    inq[v]=1;
                    q.push(v);
                }
            }
            else if(d1[v]==d1[u]+w&&d2[v]<d2[u]+a[v])
            {
                d2[v]=d2[u]+a[v];
                if(inq[v]==0)
                {
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
    ans=0;
    dfs(c2);
    printf("%d %d\n",ans,d2[c2]);
}


int main()
{
    int u,v,w;
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++) g[i].clear();
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        node t;
        t.to=v;
        t.w=w;
        g[u].push_back(t);
        t.to=u;
        g[v].push_back(t);
    }
    spfa();
    return 0;
}
