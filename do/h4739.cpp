#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct node
{
    int x,y;
} a[25];
int n,ans,b[25],use[25];

double dis(int n1,int n2)
{
    return (a[n1].x-a[n2].x)*(a[n1].x-a[n2].x)+(a[n1].y-a[n2].y)*(a[n1].y-a[n2].y);
}

int check(int z,int x,int c,int v)
{
    double t1,t2,t3;
    t1=dis(z,x);
    t2=dis(z,c);
    t3=dis(z,v);
    if(t2>t1) swap(t1,t2);
    if(t3>t1) swap(t1,t3);
    if(t1!=t2+t3||t2!=t3) return 0;
    t1=dis(x,c);
    t2=dis(x,z);
    t3=dis(x,v);
    if(t2>t1) swap(t1,t2);
    if(t3>t1) swap(t1,t3);
    if(t1!=t2+t3||t2!=t3) return 0;
    return 1;
}

void dfs(int now,int cnt)
{
    int i,t=0;
    for(i=0; i+3<cnt; i+=4)
        if(check(b[i+0],b[i+1],b[i+2],b[i+3])==0)
            return;
        else t+=4;
    if(t>ans) ans=t;
    if(cnt==n-1||n-ans<4) return;
    b[cnt]=now;
    for(i=0;i<n;i++)
    {
        if(use[i]==0)
        {
            use[i]=1;
            dfs(i,cnt+1);
            use[i]=0;
        }
    }
}

int main()
{
    int i;
    while(~scanf("%d",&n))
    {
        if(n==-1) break;
        for(i=0; i<n; i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        if(n<=3)
        {
            printf("0\n");
            continue;
        }
        ans=0;
        memset(use,0,sizeof(use));
        for(i=0;i<n;i++)
        {
            use[i]=1;
            dfs(i,0);
            use[i]=0;
        }
        printf("%d\n",ans);
    }
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct node
{
    int x,y;
} a[25];
int n,ans,b[25],use[25];

double dis(int n1,int n2)
{
    return (a[n1].x-a[n2].x)*(a[n1].x-a[n2].x)+(a[n1].y-a[n2].y)*(a[n1].y-a[n2].y);
}

int check(int z,int x,int c,int v)
{
    double t1,t2,t3;
    t1=dis(z,x);
    t2=dis(z,c);
    t3=dis(z,v);
    if(t2>t1) swap(t1,t2);
    if(t3>t1) swap(t1,t3);
    if(t1!=t2+t3||t2!=t3) return 0;
    t1=dis(x,c);
    t2=dis(x,z);
    t3=dis(x,v);
    if(t2>t1) swap(t1,t2);
    if(t3>t1) swap(t1,t3);
    if(t1!=t2+t3||t2!=t3) return 0;
    return 1;
}

int main()
{
    int i,t;
    while(~scanf("%d",&n))
    {
        if(n==-1) break;
        for(i=0; i<n; i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        if(n<=3)
        {
            printf("0\n");
            continue;
        }
        ans=0;
        for(i=0; i<n; i++)
            b[i]=i;
        do
        {
            t=0;
            for(i=0; i+3<n; i+=4)
                if(check(b[i+0],b[i+1],b[i+2],b[i+3])==0)
                    break;
                else t+=4;
            if(t>ans) ans=t;
            if(n-ans<4) break;
        }
        while(next_permutation(b,b+n));
        printf("%d\n",ans);
    }
    return 0;
}
*/
