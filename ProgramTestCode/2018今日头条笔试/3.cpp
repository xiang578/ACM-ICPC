#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int N = 3000+10;
int n,m,p;
int now[N];

struct node
{
    int id;
    int now;
    friend bool operator < (node n1,node n2)
    {
        if(n1.now==n2.now) return n2.id<n1.id;
        return n2.now<n1.now;
    }
};

priority_queue<node>q;
struct idea
{
	int id;
	int n;
	int time;
	int kind;
	int cost;
	int ans;
}P[N];

int cmp1(idea a,idea b)
{
	return a.n<b.n;
}
int cmp2(idea a,idea b)
{
	return a.time<b.time;
}
int pm[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	int now = 0x7ffffff;
	for(int i=0;i<p;i++)
	{
		scanf("%d%d%d%d",&P[i].id,&P[i].time,&P[i].kind,&P[i].cost);
		P[i].n=i;
		P[i].ans = -1;
		now = min(P[i].time,now);
	}
	for(int i=0;i<m;i++)
	{
		node t;
		t.id = i;
		t.now = 0;
		q.push(t);
	}
	int k;
	int mp=0;
	sort(P,P+p,cmp2);
	for(int i=0;i<p;i++)
	{
		now = max(P[mp].time,q.top().now);
		for(int j=0;j<p;j++)
		{
			pm[j] = -1;
		}
		for(int j=0;j<p;j++)
		{
			//printf("  %d %d\n",P[j].n,P[j].ans);
			if(P[j].ans != -1) continue;
			if(P[j].time>now) break;
			if(pm[P[j].id]==-1) pm[P[j].id]=j;
			else 
			{
				int k=pm[P[j].id];
				if(P[k].kind==P[j].kind)
				{
					if(P[k].cost==P[j].cost)
					{
						if(P[k].time>P[j].time)
							k=j;
					}
					else if(P[k].cost>P[j].cost)
					{
						k=j;
					}
				}
				else if(P[k].kind<P[j].kind)
				{
					k = j;
				}
				pm[P[j].id] = k;
			}
		}
		k=-1;
		//printf("%d:",now);
		for(int j=0;j<p;j++)
		{
			//printf("%d ",pm[j]);
			if(pm[j]==-1) continue;
			if(k==-1) k=pm[j];
			if(P[k].cost>P[pm[j]].cost)
				k=pm[j];
			if(P[k].cost==P[pm[j]].cost&&P[k].id>P[pm[j]].id)
				k=pm[j];

		}
		//printf("\n!!%d\n",P[k].n);
		node t = q.top();
		q.pop();
		t.now= max(t.now,P[k].time)+P[k].cost;
		P[k].ans = t.now;
		q.push(t);
		if(k==mp) mp++;
	}
	sort(P,P+p,cmp1);
	for(int i=0;i<p;i++)
	{
		printf("%d\n",P[i].ans);
	}
    return 0;
}