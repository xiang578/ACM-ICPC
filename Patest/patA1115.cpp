#include<bits/stdc++.h>
using namespace std;
struct node
{
    int l,r,num,cnt;
}p[10000];
int n,cnt1,cnt2,mx;

void get(int x,int y)
{
    if(p[x].num>=p[y].num)
    {
        if(p[x].l==-1)
        {
            p[x].l=y;
        }
        else get(p[x].l,y);
    }
    else
    {
        if(p[x].r==-1)
        {
            p[x].r=y;
        }
        else get(p[x].r,y);
    }
}
void dfs(int x,int t)
{
    if(t>mx) mx=t;
    p[x].cnt=t;
    if(p[x].l!=-1) dfs(p[x].l,t+1);
    if(p[x].r!=-1) dfs(p[x].r,t+1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].num;
        p[i].l=p[i].r=-1;
        p[i].cnt=-1;
        if(i==0) continue;
        else get(0,i);
    }
    cnt1=cnt2=0;
    mx=0;
    dfs(0,1);
    for(int i=0;i<n;i++)
    {
        if(p[i].cnt==mx) cnt1++;
        if(p[i].cnt==mx-1) cnt2++;
    }
    printf("%d + %d = %d\n",cnt1,cnt2,cnt1+cnt2);
    return 0;
}
