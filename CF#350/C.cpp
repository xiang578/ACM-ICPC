#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct node
{
	int a,b,n;
}p[200000+10];
map<int,int>mp;
int v[200000+10];
int cmp(node x,node y)
{
	if(x.a==y.a)
		return x.b>y.b;
	else
		return x.a>y.a;
}
int main()
{
	int n,m,t,tot,a,b;
	while(~scanf("%d",&n))
	{
		memset(v,0,sizeof(v));
		mp.clear();
		tot=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			if(mp[t]==0) mp[t]=++tot;
			v[mp[t]]++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a);
			p[i].n=i;
			p[i].a=v[mp[a]];
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&b);
			p[i].b=v[mp[b]];
		}
		sort(p+1,p+1+m,cmp);
		printf("%d\n",p[1].n);
	}
	return 0;
}
