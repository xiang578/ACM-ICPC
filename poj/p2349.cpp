#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAXN=1024;//最大点数
const int MAXM=500000;//最大边数
int bin[MAXN];//并查集使用
double use[MAXM];

struct Edge
{
    int u,v;
    double w;
}edges[MAXM]; //存储边的信息，包括起点/终点/权值
int tol,m;//边数，加边前赋值为0

void addedge(int u,int v,double w)
{
    edges[tol].u=u;
    edges[tol].v=v;
    edges[tol++].w=w;
}

bool cmp(Edge a,Edge b)
{
    //排序函数，讲边按照权值从小到大排序
    return a.w<b.w;
}
bool cmp1(double x1,double x2)
{
    return x1>x2;
}

int Find(int x)
{
    if(bin[x]==-1)return x;
    else return bin[x]=Find(bin[x]);
}
double Kruskal(int n)//传入点数，返回最小生成树的权值，如果不连通返回-1
{
    memset(bin,-1,sizeof(bin));
    sort(edges,edges+tol,cmp);
    int cnt=0;//计算加入的边数
    for(int i=0; i<tol; i++)
    {
        int u=edges[i].u;
        int v=edges[i].v;
        double w=edges[i].w;
        int t1=Find(u);
        int t2=Find(v);
        if(t1!=t2)
        {
            use[cnt]=w;
            bin[t1]=t2;
            cnt++;
        }
        if(cnt==n-m) return w;
    }
}

int main()
{
    int _,n,i,j;
    double a[1024],b[1024],t;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&m,&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&a[i],&b[i]);
        }
        tol=0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
        {
            t=sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
            addedge(i,j,t);
        }
        printf("%.2f\n",Kruskal(n));
    }
    return 0;
}
