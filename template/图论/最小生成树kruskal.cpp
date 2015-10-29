//kruskal
const int MAXN=1024;//最大点数
const int MAXM=1024*1024;//最大边数
int bin[MAXN];//并查集使用

struct Edge
{
    int u,v,w;
}edges[MAXM]; //存储边的信息，包括起点/终点/权值
int tol;//边数，加边前赋值为0

void addedge(int u,int v,int w)
{
    edges[tol].u=u;
    edges[tol].v=v;
    edges[tol++].w=w;
}

bool cmp(Edge a,Edge b) //排序函数，讲边按照权值从小到大排序
{
    return a.w<b.w;
}

int Find(int x)
{
    if(bin[x]==-1)return x;
    else return bin[x]=Find(bin[x]);
}
int Kruskal(int n)//传入点数，返回最小生成树的权值，如果不连通返回-1
{
    memset(bin,-1,sizeof(bin));
    sort(edges,edges+tol,cmp);
    int cnt=0;//计算加入的边数
    int ans=0;
    for(int i=0; i<tol; i++)
    {
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;
        int t1=Find(u);
        int t2=Find(v);
        if(t1!=t2)
        {
            ans+=w;
            bin[t1]=t2;
            cnt++;
        }
        if(cnt==n-1)break;
    }
    if(cnt<n-1) return -1;//不连通
    else return ans;
}

