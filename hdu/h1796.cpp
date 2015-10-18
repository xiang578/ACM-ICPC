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

int n,cnt,a[20],ans;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

void dfs(int cur,int lcm,int num)
{
    lcm=a[cur]/gcd(a[cur],lcm)*lcm;
    if(num%2==1)
        ans+=(n-1)/lcm;
    else
        ans-=(n-1)/lcm;
    for(int i=cur+1;i<cnt;i++)
        dfs(i,lcm,num+1);
}
int main()
{
    int m,i,t;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0,cnt=0;i<m;i++)
        {
            scanf("%d",&t);
            if(t) a[cnt++]=t;
        }
        ans=0;
        for(i=0;i<cnt;i++)
            dfs(i,a[i],1);
        printf("%d\n",ans);
    }
    return 0;
}
