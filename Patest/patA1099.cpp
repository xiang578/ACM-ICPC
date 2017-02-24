#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l,r,num,lcnt,rcnt;
}p[1024];
int n,a[1024];

int dfs(int x)
{
    int ret=1;
    p[x].lcnt=0;
    p[x].rcnt=0;
    if(p[x].l!=-1) p[x].lcnt=dfs(p[x].l);
    if(p[x].r!=-1) p[x].rcnt=dfs(p[x].r);
    ret+=p[x].lcnt+p[x].rcnt;
    return ret;
}

void get(int x,int l,int r)
{
    //printf("%d %d %d\n",x,l,r);
    if(l==r) {p[x].num=a[l];return ;}
    else
    {
        if(p[x].l==-1)
        {
            p[x].num=a[l];
            get(p[x].r,l+1,r);
        }
        else if(p[x].r==-1)
        {
            p[x].num=a[r];
            get(p[x].l,l,r-1);
        }
        else
        {
            p[x].num=a[l+p[x].lcnt];

            get(p[x].l,l,l+p[x].lcnt-1);
            get(p[x].r,l+p[x].lcnt+1,r);
        }
    }
}
int main()
{

    vector<int>ans;
    queue<int>q;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].l>>p[i].r;
        p[i].lcnt=p[i].rcnt=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(0);
    get(0,1,n);
    q.push(0);
    //printf("!!!!");
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        ans.push_back(p[x].num);
        if(p[x].l!=-1)q.push(p[x].l);
        if(p[x].r!=-1)q.push(p[x].r);
    }
    for(int i=0;i<ans.size();i++)
    {
        if(i) printf(" ");
        printf("%d",ans[i]);
    }
    puts("");
    return 0;
}
