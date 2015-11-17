const int MAXN=3000+5;
const int MAXM=MAXN*MAXN;

struct Edge
{
    int to,next;
} edge[MAXM],e2[MAXM];
int head[MAXN],h2[MAXN],tot,mx[MAXN],cx[MAXN],cy[MAXN];

void addedge(int from,int to)
{
    edge[tot].to=to;
    edge[tot].next=head[from];
    head[from]=tot;

    e2[tot].to=from;
    e2[tot].next=h2[to];
    h2[to]=tot++;
}


void init()
{
    memset(head,0xff,sizeof(head));
    memset(h2,0xff,sizeof(h2));
    tot=0;
}

int Maxmatch(int n,int m)
{
    int i,j,y,cur,tail,res=0;
    int q[MAXN*10];
    int p[MAXN];
    memset(cx,0xff,sizeof(cx));
    memset(cy,0xff,sizeof(cy));
    memset(p,0xff,sizeof(p));
    for(int i=1; i<=n; i++)
    {
        if(cx[i]!=-1) continue;
        for(j=1;j<=m;j++) p[j]=-2;
        cur=tail=0;
        for(j=head[i];j!=-1;j=edge[j].next)
        {
            y=edge[j].to;
            p[y]=-1;
            q[tail++]=j;
        }
        while(cur<tail)
        {
            y=q[cur];
            if(cy[y]==-1) break;
            cur++;
            for(j=h2[y];j!=-1;j=e2[j].next)
            {
                int v=e2[j].to;
                if(p[v]==-2)
                {
                    p[v]=y;
                    q[tail++]=v;
                }
            }
        }

        if(cur==tail) continue;
        while(p[y]>-1)
        {
            cx[cy[p[y]]]=y;
            cy[y]=cy[p[y]];
            y=p[y];
        }
        cy[y]=i;
        cx[i]=y;
        res++;
    }
    return res;
}
