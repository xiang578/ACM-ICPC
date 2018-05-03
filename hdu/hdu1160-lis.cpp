//#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=1024;
int f[N],a[N],d[N];

struct node
{
    int w,s,id;
} p[N];

int cmp(node a,node b)
{
    if(a.w==b.w)
        return a.s>b.s;
    else
        return a.w<b.w;
}

int main()
{
    int n=0,k=0,i,j,st,w,s,ans=0,t;
    memset(a,0xff,sizeof(a));
    while(~scanf("%d%d",&p[n].w,&p[n].s))
    {
        p[n].id=n+1;
        n++;
    };
    sort(p,p+n,cmp);
    for(i=0; i<n; i++)
    {
        d[i]=1;
        for(j=0; j<i; j++)
        {
            w=p[j].w;
            s=p[j].s;
            if(p[i].w>w&&p[i].s<s&&d[i]<d[j]+1)
            {
                d[i]=d[j]+1;
                a[i]=j;
            }
        }
        if(d[i]>ans) {st=i;ans=d[i];}
    }

    vector<int>v;
    v.clear();
    //printf("  %d\n",p[st].id);
    while(st!=-1)
    {
        v.push_back(p[st].id);
        st=a[st];
    }
    printf("%d\n",v.size());
    for(i=v.size()-1; i>=0; i--)
        printf("%d\n",v[i]);
    return 0;
}
