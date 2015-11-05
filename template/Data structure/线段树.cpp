typedef long long ll; //通过这里调整值的范围
const int N=1024;
int a[N];

struct Tree
{
    int left,right;     //区间的端点
    ll sum;   //视题目要求而定
}tree[4*N+10];//线段树数组大小是原数据的4倍

//建立线段树，如果是数组a1-an，可以build(1,1,n)来建立
void build(int id,int l,int r)
{
    tree[id].left=l;
    tree[id].right=r;
    if (l==r)
        tree[id].sum=a[l];
    else
    {
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    }
}

//单点更新，id从1开始，pos为目标位置
void update(int id,int pos,ll val)
{
    if (tree[id].left==tree[id].right)
        tree[id].sum=val;
    else
    {
        int mid=(tree[id].left+tree[id].right)/2;
        if (pos<=mid) update(id*2,pos,val);
        else update(id*2+1,pos,val);
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    }
}

//查询范围内的和
ll query(int id,int l,int r)
{
    if (tree[id].left==l&&tree[id].right==r)
        return tree[id].sum; //询问总和
    else
    {
        int mid=(tree[id].left+tree[id].right)/2;
        if (r<=mid) return query(id*2,l,r);
        else if (l>mid) return query(id*2+1,l,r);
        else return query(id*2,l,mid)+query(id*2+1,mid+1,r);
    }
}
