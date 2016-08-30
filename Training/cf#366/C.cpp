/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=1e6;
int use[N],cnt[N];
struct node
{
    int x,i;
}tmp;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,qt,ans=0,t,m,tot=0;
    scanf("%d%d",&n,&qt);
    memset(use,0,sizeof(use));
    memset(cnt,0,sizeof(cnt));
    queue<node>q;
    for(int i=1;i<=qt;i++)
    {
        scanf("%d%d",&t,&m);
        if(t==1)
        {
            cnt[m]++;
            ans++;
            tmp.x=m;
            tmp.i=++tot;
            q.push(tmp);
        }
        else if(t==2)
        {
            ans-=cnt[m];
            cnt[m]=0;
            use[m]=tot;
        }
        else if(t==3)
        {
            while(!q.empty()&&q.front().i<=m)
            {
                if(q.front().i>use[q.front().x])
                {
                    ans--;
                    cnt[q.front().x]--;
                }
                q.pop();
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
