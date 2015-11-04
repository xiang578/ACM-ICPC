const int sigm_size=26;
const int maxnode=400000+5;
int sz; //结点
int ch[maxnode][sigm_size],val[maxnode];

int idx(char c)
{
    return c-'a';
}

void init()
{
    sz=1;
    memset(ch[0],0,sizeof(ch[0]));//初始化根结点
}

void trie(char *s,int v)
{
    int c,i,j,u=0,n=strlen(s);
    for(i=0;i<n;i++)
    {
        c=idx(s[i]);
        if(!ch[u][c])//结点不存在
        {
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz]=0;
            ch[u][c]=sz++;//新建结点
        }
        u=ch[u][c];//往下走
    }
    val[u]=v;//字符串最后一个字符的附加信息
}
