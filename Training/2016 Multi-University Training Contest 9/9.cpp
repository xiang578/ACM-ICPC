#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
const int M=50000;

struct Node{
	int x,y,next,cap;
}edge[M*3];
struct Node1{
	int x,y,id;
}a[210];
vector<int> V[210];
int c[210],d[210];
const int inf=1<<30;
int head[250],nc;

bool cmp(Node1 a,Node1 b){
	return a.y<b.y;
}

void add(int x,int y,int cap){
	edge[nc].x=x;
	edge[nc].y=y;
	edge[nc].cap=cap;
	edge[nc].next=head[x];
	head[x]=nc++;
	edge[nc].x=y;
	edge[nc].y=x;
	edge[nc].cap=0;
	edge[nc].next=head[y];
	head[y]=nc++;
}
int num[250],h[250],S,T,N;
int findpath(int x,int flow){
	if(x==T)
		return flow;
	int res=flow;
	int pos=N-1;
	for(int i=head[x];i!=-1;i=edge[i].next){
		int y=edge[i].y;
		if(h[x]==h[y]+1&&edge[i].cap>0){
			int tp=findpath(y,min(edge[i].cap,res));
			res-=tp;
			edge[i].cap-=tp;
			edge[i^1].cap+=tp;
			if(!res||h[S]==N)
				return flow-res;
		}
		if(edge[i].cap>0&&h[y]<pos)
			pos=h[y];
	}
	if(res==flow){
		num[h[x]]--;
		if(num[h[x]]==0){
			h[S]=N;
			return flow-res;
		}
		h[x]=pos+1;
		num[h[x]]++;
	}
	return flow-res;
}
void Sap(){
	memset(h,0,sizeof(h));
	memset(num,0,sizeof(num));
	int ans=0;
	while(h[S]!=N)
		ans+=findpath(S,inf);
	return;
}
bool vis[250];
int aa[250];
int dfs(int now,int &val){
	int cnt=1;
	vis[now]=true;
	val+=aa[now];
	for(int i=head[now];i!=-1;i=edge[i].next){
		if(!vis[edge[i].y]&&edge[i].cap>0)
			cnt+=dfs(edge[i].y,val);
	}
	return cnt;
}
int main(){
	int T,n,m,l,x,y;
	scanf("%d",&T);
	while(T--){
		memset(head,-1,sizeof(head));
		nc=0;
		scanf("%d%d%d",&n,&m,&l);
		S=0;T=n+m+1;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].id=i;
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&c[i]);
			V[i].clear();
			scanf("%d",&x);
			d[i]=0;
			for(int j=0;j<x;j++){
				scanf("%d",&y);
				V[i].push_back(y);
				d[i]=max(d[i],a[y].y);
			}
		}
		sort(a+1,a+1+n,cmp);
		int sum=0;
		for(int i=1;i<=n;i++){
			cout << i << endl;
			if(i<n&&a[i].y==a[i+1].y) continue;
			memset(head,-1,sizeof(head));
			nc=0;
			for(int j=1;j<=i;j++)
				add(T,i,a[j].x);
			for(int j=1;j<=m;j++)
				if(d[j]<=a[i].y){
					add(S,j+n,c[i]);
					for(int k=0;k<V[j].size();k++)
						add(j+n,V[j][k],inf);
				}
			N=T+1;
			cout << "yes1\n";
			Sap();
			cout << "yes2\n";
			aa[S]=0;
			memset(vis,false,sizeof(vis));
			int nn;
			int ans=0;
			nn=dfs(S,ans)-1;
			printf("%d %d\n",nn,ans);
			if(ans>=l){
				sum=l;
				break;
			}
		}
		cout << sum << endl;
	}
}
