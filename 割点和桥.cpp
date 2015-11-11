const int MAXN = 10010;
const int MAXM = 100010;
struct Edge
{
    int to,next;
    bool cut;//�Ƿ�Ϊ�ŵı��
} edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN];
int Index,top;
bool Instack[MAXN];
bool cut[MAXN];
int add_block[MAXN];//ɾ��һ��������ӵ���ͨ��
int bridge;
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].cut = false;
    head[u] = tot++;
}
void Tarjan(int u,int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    int son = 0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if(v == pre)continue;
        if( !DFN[v] )
        {
            son++;
            Tarjan(v,u);
            if(Low[u] > Low[v])Low[u] = Low[v];
//��
//һ�������(u,v)���ţ����ҽ���(u,v)Ϊ��֦�ߣ�������DFS(u)<Low(v)��
            if(Low[v] > DFN[u])
            {
                bridge++;
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
//���
//һ������u�Ǹ�㣬���ҽ�������(1)��(2) (1) uΪ��������u�ж���һ��������
//(2) u��Ϊ���������������(u,v)Ϊ��֦��(��Ƹ��ӱߣ�
//��uΪv���������еĸ���)��ʹ��DFS(u)<=Low(v)
            if(u != pre && Low[v] >= DFN[u])//��������
            {
                cut[u] = true;
                add_block[u]++;
            }
        }
        else if( Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
//��������֧������1
    if(u == pre && son > 1)cut[u] = true;
    if(u == pre)add_block[u] = son - 1;
    Instack[u] = false;
    top--;
}


//�����ر�
map<int,int>mapit;
inline bool isHash(int u,int v)
{
    if(mapit[u*MAXN+v])return true;
    if(mapit[v*MAXN+u])return true;
    mapit[u*MAXN+v] = mapit[v*MAXN+u] = 1;
    return false;
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        init();
        int u;
        int k;
        int v;
//mapit.clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d (%d)",&u,&k);
            u++;
//�����ӱߣ�Ҫ��֤���ߺͷ��������ڵģ�������ͼ
            while(k--)
            {
                scanf("%d",&v);
                v++;
                if(v <= u)continue;
//if(isHash(u,v))continue;
                addedge(u,v);
                addedge(v,u);
            }
        }
        solve(n);
    }
    return 0;
}
