#include<bits/stdc++.h>
using namespace std;
const int N=1024;
int n;
double has[4*N];
struct Tree
{
    int cover;
    double len;
}t[4*N+10];

struct line
{
    double a1,a2,b;
    int f;
}li[N];

int cmp(line n1,line n2)
{
    return n1.b<n2.b;
}

void build(int o,int l,int r)
{
    t[o].len=0;
    t[o].cover=0;
    if(l!=r)
    {
        int mid=(l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
    }
}

void get(int o,int l,int r)
{
    if(t[o].cover) t[o].len=has[r+1]-has[l];
    else
    {
        if(l==r) t[o].len=0;
        else
        {
            t[o].len=t[o*2+1].len+t[o*2].len;
        }
    }
}

void update(int o,int l,int r,int x,int y,int val)
{
    if(x<=l&&r<=y)
    {
        t[o].cover+=val;
        get(o,l,r);
        return ;
    }
    int mid=(l+r)/2;
    if(x<=mid) update(o*2,l,mid,x,y,val);
    if(y>mid) update(o*2+1,mid+1,r,x,y,val);
    get(o,l,r);
}
/*void update(int o,int l,int r,int x,int y,int val)
{
    //printf("%d %d %d %d\n",l,r,x,y);
    if(x<=l&&r<=y)
    {
        t[o].cover+=val;
        if(t[o].cover==0)
           t[o].len=t[o*2].len+t[o*2+1].len;
        else
            {
                printf("%lf %lf %d %d\n",has[r],has[l],r,l);
                t[o].len=has[r]-has[l];
            }
    }
    else
    {
        int mid=(l+r)/2;
        if(t[o].cover)
        {
            t[o*2].cover+=t[o].cover;
            t[o*2+1].cover+=t[o].cover;
            t[o*2].len=has[mid]-has[l];
            t[o*2+1].len=has[r]-has[mid+1];
            t[o].cover=0;
        }
        if(x<=mid) update(o*2,l,mid,x,y,val);
        if(y>mid) update(o*2+1,mid+1,r,x,y,val);

        t[o].cover=min(t[o*2].cover,t[o*2+1].cover);
        t[o*2].cover-=t[o].cover;
        get(o*2,l,mid);

        t[o*2+1].cover-=t[o].cover;
        get(o*2+1,mid+1,r);

        if(t[o].cover) t[o].len=has[r]-has[l];
        else t[o].len=t[o*2+1].len+t[o*2].len;
    }
}*/

int main()
{
    int _=0;
    double ans,a1,a2,b1,b2;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&a1,&b1,&a2,&b2);
            li[i*2-1].a1=li[i*2].a1=a1;
            li[i*2-1].a2=li[i*2].a2=a2;
            li[i*2-1].b=b1;li[i*2].b=b2;
            li[i*2-1].f=1;li[i*2].f=-1;
            has[i*2-1]=a1;has[i*2]=a2;
        }
        //li[0].b=0;
        sort(li+1,li+2*n+1,cmp);
        li[0].b=li[1].b;
        sort(has+1,has+2*n+1);
        build(1,1,2*n);
        ans=0;
        for(int i=1;i<2*n;i++)
        {
            int l=lower_bound(has+1,has+2*n+1,li[i].a1)-has;
            int r=lower_bound(has+1,has+2*n+1,li[i].a2)-has-1;
            update(1,1,2*n,l,r,li[i].f);
            ans+=t[1].len*(li[i+1].b-li[i].b);
            //printf("%d %lf %d %lf %lf :%lf\n",l,has[l],r,has[r],t[1].len,ans);
        }
        printf("Test case #%d\n",++_);
        printf("Total explored area: %.2f\n",ans);
        printf("\n");
    }
    return 0;
}
