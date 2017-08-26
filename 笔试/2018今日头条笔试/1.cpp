#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int N = 500000+10;
int n,s[N];
vector<int>ans;
struct node
{
    int x,y;
}p[N];

int cmp(node a,node b)
{
    if(b.x==a.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    sort(p,p+n,cmp);
    int cnt = -1;
    for(int i=0;i<n;i++)
    {
        while(cnt!=-1&&p[s[cnt]].y<p[i].y)
        {
            cnt--;
        }
        cnt++;
        s[cnt]=i;
        //printf("%d %d %d %d\n",p[i].x,p[i].y,i,cnt);
    }
    for(int i=0;i<=cnt;i++)
    {
        printf("%d %d\n",p[s[i]].x,p[s[i]].y);
    }
    return 0;
}