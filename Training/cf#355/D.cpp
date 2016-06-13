/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll mod=1000000007;
const int N=300+10;
struct node
{
	int x,y;
}t,cur;
vector<node>v[N*N];
int n,m,p,dp[N][N],a[N][N],vis[N][N],inq[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(~scanf("%d%d%d",&n,&m,&p))
	{
		for(int i=1;i<=p;i++)
			v[i].clear();
		memset(dp,inf,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				t.x=i;
				t.y=j;
				v[a[i][j]].push_back(t);
				if(a[i][j]==1)
				{
					dp[i][j]=abs(i-1)+abs(j-1);
				}
			}
		}
		for(int i=1;i<p;i++)
		{
			if(v[i].size()*v[i+1].size()<=n*m)
			{
				for(int j=0;j<v[i].size();j++)
				{
					int x=v[i][j].x,y=v[i][j].y;
					for(int k=0;k<v[i+1].size();k++)
					{
						int nx=v[i+1][k].x,ny=v[i+1][k].y;
						dp[nx][ny]=min(dp[nx][ny],dp[x][y]+abs(nx-x)+abs(ny-y));
					}
				}
			}
			else
			{
				memset(vis,inf,sizeof(vis));
				memset(inq,0,sizeof(inq));
				queue<node>q;
				for(int j=0;j<v[i].size();j++)
				{
					q.push(v[i][j]);
					inq[v[i][j].x][v[i][j].y]=1;
					vis[v[i][j].x][v[i][j].y]=dp[v[i][j].x][v[i][j].y];
				}
				while(!q.empty())
				{
					cur=q.front();
					q.pop();
					inq[cur.x][cur.y]=0;
					for(int j=0;j<4;j++)
					{
						t.x=cur.x+dx[j];
						t.y=cur.y+dy[j];
						if(t.x<=0||t.x>n||t.y<=0||t.y>m) continue;
						//if(a[cur.x][cur.y]+1!=a[t.x][t.y]) continue;
						int tmp=vis[cur.x][cur.y]+abs(cur.x-t.x)+abs(cur.y-t.y);
						if(vis[t.x][t.y]>tmp)
						{
							vis[t.x][t.y]=tmp;
							if(inq[t.x][t.y]==0)
							{
								inq[t.x][t.y]=1;
								q.push(t);
							}
						}
					}
				}
				for(int j=0;j<v[i+1].size();j++)
				{
					dp[v[i+1][j].x][v[i+1][j].y]=vis[v[i+1][j].x][v[i+1][j].y];
				}
			}
		}
		printf("%d\n",dp[v[p][0].x][v[p][0].y]);
	}
    return 0;
}
