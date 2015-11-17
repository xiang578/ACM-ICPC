const int MAXN=1024;
const int MAXM=1024*100;

struct Edge
{
    int to,next;
} edge[MAXM];
int head[MAXN],tot,mx[MAXN],cx[MAXN],mk[MAXN];

void addedge(int from,int to)
{
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot++;
}

void init()
{
    memset(head,0xff,sizeof(head));
    tot=0;
}

int dfs(int u)
{
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(!mk[v])
        {
            mk[v]=1;
            if(cx[v]==-1||dfs(cx[v]))
            {
                cx[v]=u;
                return 1;
            }
        }
    }
    return 0;
}

int Maxmatch(int n)
{
    int res=0;
    memset(cx,0xff,sizeof(cx));
    for(int i=1; i<=n; i++)
    {
        memset(mk,0,sizeof(mk));
        res+=dfs(i);
    }
    return res;
}
