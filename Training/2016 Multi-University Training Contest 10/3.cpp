#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Xianduan
{
public:
    int x1;
    int y1;
    int x2;
    int y2;
}xian[1000000+100];
int a[1000000+100];
class Duan
{
public:
    int val;
    int with;
    int shang;
    int xia;
public:
    bool operator <(const Duan &t)const
    {
        if(val==t.val)return with>t.with;
        return val<t.val;
    }
}duan[1000000+100];
int c[10000000];
long long sum(int x)
{
    long long ret=0,i;
    for(int i=x;i>0;i-=(i&-i))
        ret+=c[i];
    return ret;
}
long long add(int x,int d)
{
    int i;
    for(int i=x;i<=10000000-1;i+=(i&-i))
    {
        c[i]+=d;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&xian[i].x1,&xian[i].y1,&xian[i].x2,&xian[i].y2);
            if(xian[i].x1==xian[i].x2&&xian[i].y1<xian[i].y2)
                swap(xian[i].y1,xian[i].y2);
            if(xian[i].y1==xian[i].y2&&xian[i].x1>xian[i].x2)
                swap(xian[i].x1,xian[i].x2);
            a[cnt++]=xian[i].y1;
            a[cnt++]=xian[i].y2;
        }
        sort(a+1,a+cnt);
        for(int i=1;i<=n;i++)
        {
            xian[i].y1=lower_bound(a+1,a+cnt,xian[i].y1)-a;
            xian[i].y2=lower_bound(a+1,a+cnt,xian[i].y2)-a;
        }
        cnt=1;
        for(int i=1;i<=n;i++)
        {
            if(xian[i].x1!=xian[i].x2)
            {
                duan[cnt].val=xian[i].x1;
                duan[cnt].with=1;
                duan[cnt++].shang=xian[i].y1;
                duan[cnt].val=xian[i].x2;
                duan[cnt].with=-1;
                duan[cnt++].shang=xian[i].y1;
            }
            else
            {
                duan[cnt].val=xian[i].x1;
                duan[cnt].with=0;
                duan[cnt].shang=xian[i].y1;
                duan[cnt++].xia=xian[i].y2;
            }
        }
        memset(c,0,sizeof(c));
        sort(duan+1,duan+cnt);
        long long summ=0;
        for(int i=1;i<=cnt-1;i++)
        {
            if(duan[i].with==0)
            {
                summ+=sum(duan[i].shang)-sum(duan[i].xia-1);
            }
            else
            {
                add(duan[i].shang,duan[i].with);
            }
        }
        printf("%I64d\n",summ);
    }
}
