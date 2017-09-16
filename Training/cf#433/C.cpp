#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <set>
#include <time.h>
#include <cmath>
using namespace std;
const int N=300000+10;
struct node
{
    int t;
    int c;
    friend bool operator < (node a,node b)
    {
        if(a.c==b.c)
            return a.t>b.t;
        else
            return a.c<b.c;
    }
};

priority_queue<node>pq;

int k,n,c[N],t[N];

int main()
{
    long long ans;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",c+i);
    for(int i=1;i<=k;i++)
    {
        node t;
        t.t=i;
        t.c=c[i];
        pq.push(t);
    }
    ans=0;
    for(int i=k+1;i<=k+n;i++)
    {
        if(i<=n)
        {
            node t;
            t.t=i;
            t.c=c[i];
            pq.push(t);
        }
        node k=pq.top();
        //printf("%d\n",k.c);
        pq.pop();
        ans+=((long long)(i-k.t))*(k.c);
        t[k.t]=i;
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)
        printf("%d ",t[i]);
    return 0;
}
