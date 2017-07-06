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
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
#define cl(a) memset(a,0,sizeof(a))
typedef vector<int> VI;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const ll mod=1000000007;
const int N=1e4+5;
const int inf=0x7fffffff;
const db pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
const db eps=1e-8;
int n,m,k;
struct node
{
    int x,y;
    int id;
}p[N];
int inq[N],dis[N];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int ok=0;
        for(int i=0;i<k;i++)
        {
            //printf("%d %d\n",i,k);
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].id=i;
            if(p[i].x==n&&p[i].y==m) ok=1;
        }
        if(ok==0)
        {
            p[k].x=n+1;
            p[k].y=m+1;
            p[k].id=k;
            k++;
        }
        queue<int>q;
        for(int i=0;i<k;i++)
        {
            inq[i]=0;
            dis[i]=inf;
        }
        q.push(0);
        dis[0]=0;
        inq[0]=1;
        while(!q.empty())
        {
            int x=q.front();
            //printf("%d %d\n",x,dis[x]);
            q.pop();
            inq[x]=0;
            //if(x==k-1) break;
            if(x==k-1) continue;
            for(int i=0;i<k;i++)
            {
                if(i==x) continue;
                int dx=abs(p[x].x-p[i].x);
                int dy=abs(p[x].y-p[i].y);
                int w=inf;
                if(dx+dy==1) w=0;
                else if(dx<=2||dy<=2) w=1;
                if(w==inf) continue;
                if(dis[i]<=dis[x]+w) continue;
                dis[i]=dis[x]+w;
                if(dis[i]>dis[k-1]) continue;
                if(inq[i]==0) q.push(i),inq[i]=1; 
            }
        }
        if(dis[k-1]==inf) dis[k-1]=-1;
        printf("%d\n",dis[k-1]);
    }
    return 0;
}