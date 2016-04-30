#include<bits/stdc++.h>
using namespace std;
struct node
{
    int f,c,id;
} p[1024],u[1024];

int cmp1(node a,node b)
{
    if(a.f==b.f)
        return a.c<b.c;
    return a.f<b.f;
}

int cmp2(node a,node b)
{
    return a.c<b.c;
}

int main()
{
    int _,n,v[1024],use[1024],ans,tmp,num,cnt;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        memset(v,0,sizeof(v));
        for(int i=2; i<=n; i++)
        {
            scanf("%d",&p[i].f);
            p[i].id=i;
            v[p[i].f]++;
        }
        for(int i=2; i<=n; i++)
            scanf("%d",&p[i].c);
        sort(p+2,p+1+n,cmp1);
        for(int i=2; i<=n; i++)
            u[i]=p[i];
        sort(u+2,u+1+n,cmp2);
        int ans=0x7fffffff;
        for(int i=n; i>=max(2,v[1]); i--)
        {
            tmp=0;
            num=v[1];
            memset(use,0,sizeof(use));
            for(int j=2; j<=n; j++)
            {
                if(v[j]>i-1)
                {
                    int cnt=v[j]-i+1;
                    for(int k=2; k<=n; k++)
                    {
                        if(p[k].f!=j) continue;
                        use[p[k].id]=1;
                        tmp+=p[k].c;
                        num++;
                        cnt--;
                        if(cnt==0) break;
                    }
                }
            }
            if(num<i)
            {
                for(int k=2; k<=n;k++)
                {
                    if(num>=i) break;
                    if(u[k].f==1||use[u[k].id]==1) continue;
                    tmp+=u[k].c;
                    num++;
                }
            }
            ans=min(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
