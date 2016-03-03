#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,t;
}p[100000+10];

int cmp(node a,node b)
{
    return a.t<b.t;
}
int dp[100000+10][11],use[100000+10][11];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        for(i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].t);
        sort(p,p+n,cmp);
        for
    }
    return 0;
}
