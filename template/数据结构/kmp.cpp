//kmp优化版
//求特征向量
void findnext(char *p,int *next)
{
    int i=0,k=-1;
    int len=strlen(p);
    next[0]=-1;
    while(i<len)
    {
        while(k>=0&&p[k]!=p[i])
            k=next[k];
        i++;
        k++;
        if(i==len) break;
        //不优化版采用注释中的代码
        if(p[i]==p[k])
            next[i]=next[k];
        else
            next[i]=k;
        //next[i]=k;
    }
}

//返回模式串p在原串t中的数量，可重叠
int kmp(char *p,char *t,int *next)
{
    findnext(p,next);
    int i=0,j=0,cnt=0;
    int plen=strlen(p),tlen=strlen(t);
    if(tlen<plen) return cnt;
    while(j<tlen)
    {
        while(i!=-1&&p[i]!=t[j])
            i=next[i];
        i++;j++;
        if(i>=plen)
        {
            cnt++;
            i=0;
        }
    }
    return cnt;
}
