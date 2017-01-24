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
const ll mod=1000000007;
const int N=2048;
struct node
{
	int x,y,t,d;
};

int n,m,a1,a2,b1,b2,u[1024][1024][4];
char s[1024][1024];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int get(char c,int d,int x)
{
	//ÉÏÏÂ×óÓÒ 
	if(c=='+') return 1;
	if(c=='-')
	{
		if(d==0||d==1)
		{
			if(x==2||x==3) return 1;
			else return 0;
		} 
		else
		{
			if(x==0||x==1) return 1;
			else return 0;
		}
	}
	if(c=='|')
	{
		if(d==0||d==1)
		{
			if(x==0||x==1) return 1;
			else return 0;
		} 
		else
		{
			if(x==2||x==3) return 1;
			else return 0;
		}
	}
	if(c=='^')
	{
		if(d==0&&x==0) return 1;
		if(d==1&&x==3) return 1;
		if(d==2&&x==1) return 1;
		if(d==3&&x==2) return 1;
		return 0;
	}
	if(c=='>')
	{
		if(d==0&&x==3) return 1;
		if(d==1&&x==1) return 1;
		if(d==2&&x==2) return 1;
		if(d==3&&x==0) return 1;
		return 0;
	}
	if(c=='<')
	{
		if(d==0&&x==2) return 1;
		if(d==1&&x==0) return 1;
		if(d==2&&x==3) return 1;
		if(d==3&&x==1) return 1;
		return 0;
	}
	if(c=='v')
	{
		if(d==0&&x==1) return 1;
		if(d==1&&x==2) return 1;
		if(d==2&&x==0) return 1;
		if(d==3&&x==3) return 1;
		return 0;
	}
	if(c=='L')
	{
		if(d==0&&x==2) return 0;
		if(d==1&&x==0) return 0;
		if(d==2&&x==3) return 0;
		if(d==3&&x==1) return 0;
		return 1;
	}
	if(c=='R')
	{
		if(d==0&&x==3) return 0;
		if(d==1&&x==1) return 0;
		if(d==2&&x==2) return 0;
		if(d==3&&x==0) return 0;
		return 1;
	}
	if(c=='U')
	{
		if(d==0&&x==0) return 0;
		if(d==1&&x==3) return 0;
		if(d==2&&x==1) return 0;
		if(d==3&&x==2) return 0;
		return 1;
	}
	if(c=='D')
	{
		if(d==0&&x==1) return 0;
		if(d==1&&x==2) return 0;
		if(d==2&&x==0) return 0;
		if(d==3&&x==3) return 0;
		return 1;
	}
	if(c=='*')
	{
		return 0;	
	}
}

int bfs()
{
	node t,p;
	queue<node>q;
	memset(u,0xff,sizeof(u));
	t.x=a1;
	t.y=a2;
	t.t=0;
	t.d=0;
	u[t.x][t.y][t.d]=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		//printf("%d %d\n",t.x,t.y);
		if(t.x==b1&&t.y==b2) return t.t;
		for(int i=0;i<4;i++)
		{
			p.x=t.x+dx[i];
			p.y=t.y=dy[i]; 
			t.d=t.d%4;
			if(p.x<0||p.x>=n||p.y<0||p.y>=m) continue;
			for(int j=0;j<4;j++)
			{
				p.t=t.t+1+j;
				p.d=(t.d+j)%4;
				if(i==0)
				{
					if(get(s[t.x][t.y],t.d,i)==0||get(s[p.x][p.y],p.d,1)==0) continue;
				}
				else if(i==1)
				{
					if(get(s[t.x][t.y],t.d,i)==0||get(s[p.x][p.y],p.d,0)==0) continue;
				}
				else if(i==2)
				{
					if(get(s[t.x][t.y],t.d,i)==0||get(s[p.x][p.y],p.d,3)==0) continue;
				}
				else if(i==3)
				{
					if(get(s[t.x][t.y],t.d,i)==0||get(s[p.x][p.y],p.d,2)==0) continue;
				}
				//printf("%d %d %d\n",p.x,p.y,p.d);
				if(u[p.x][p.y][p.d]==-1||p.t<u[p.x][p.y][p.d])
				{
					u[p.x][p.y][p.d]=p.t;
					q.push(p);
				}
			}
		}
	}
	return -1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++)
			scanf("%s",s);
		scanf("%d%d",&a1,&a2);
		scanf("%d%d",&b1,&b2);
		printf("%d\n",bfs());
	}
    return 0;
}
