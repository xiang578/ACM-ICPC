int Find(int x)
{
    if(fa[x] == x)  return x;
    return fa[x] = Find(fa[x]);
}

void Unio(int x, int y)
{
    int  fx = Find(x), int fy = Find(y);
    if(fx != fy)
        fa[x] = y;
}

void init()
{
    for(int i = 0; i < n; i++)
        fa[i] = i;
}

//带权重的写法
int Find(int x)
{
    if(fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}

void Unio(int x, int y)
{
    int  fx = Find(x), int fy = Find(y);
    if(fx != fy)
        fa[x] = y, cnt[y] += cnt[x];
}

void init()
{
    for(int i = 0; i < n; i++)
        fa[i] = i, cnt[i] = 1;
}

