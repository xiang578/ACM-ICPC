/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
************************************************

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
const int N=2048;
int dx[]={1,0,1,2};
int dy[]={0,1,2,1};
int g[1024][1024],mx[1024][1024],ans;
int n,m;

struct data
{
    int x,y;
    int ans;
}t,t0;

void bfs()
{
    queue<data>q;
    t.x=0;
    t.y=0;
    t.ans=g[0][0];
    ans=max(t.ans,ans);
    mx[0][0]=t.ans;
    q.push(t);
    while(!q.empty())
    {
        t0=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            t.x=t0.x+dx[i];
            t.y=t0.y+dy[i];
            if(t.x>=n||t.y>=m) continue;
            t.ans=t0.ans+g[t.x][t.y];
            if(t.ans<0) continue;
            ans=max(t.ans,ans);
            if(t.ans>mx[t.x][t.y])
            {
                mx[t.x][t.y]=t.ans;
                q.push(t);
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        ans=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            scanf("%d",&g[i][j]);
        memset(mx,0,sizeof(mx));
        bfs();
        printf("%d\n",ans);
    }
    return 0;
}*/
/*

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
const int N=2048;
int g[1024][1024],dp[1024][1024],ans;
int n,m;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        ans=0;
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            scanf("%d",&g[i][j]);
        memset(dp,0,sizeof(dp));
        dp[0][0]=g[0][0];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(dp[i][j]<0) continue;
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+g[i+1][j]);
                dp[i][j+1]=max(dp[i][j+1],dp[i][j]+g[i][j+1]);
                dp[i+1][j+2]=max(dp[i+1][j+2],dp[i][j]+g[i][j+1]);
                dp[i+2][j+1]=max(dp[i+2][j+1],dp[i][j]+g[i+2][j+1]);

                ans=max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
*/

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
const int N=2048;
int g[1024][1024],dp[1024][1024],ans,use[1024][1024];
int n,m;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i,j;
    while(~scanf("%d%d",&n,&m))
    {
        ans=0;
        memset(g,0,sizeof(g));
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                scanf("%d",&g[i][j]);
        memset(dp,0,sizeof(dp));
        memset(use,0,sizeof(use));
        use[0][0]=1;
        dp[0][0]=g[0][0];
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(!use[i][j]) continue;
                if(dp[i][j]+g[i+1][j]>=0)
                {
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]+g[i+1][j]);
                    use[i+1][j]=1;
                }
                if(dp[i][j]+g[i][j+1]>=0)
                {
                    dp[i][j+1]=max(dp[i][j+1],dp[i][j]+g[i][j+1]);
                    use[i][j+1]=1;
                }
                if(dp[i][j]+g[i+1][j+2]>=0)
                {
                    dp[i+1][j+2]=max(dp[i+1][j+2],dp[i][j]+g[i+1][j+2]);
                    use[i+1][j+2]=1;
                }
                if(dp[i][j]+g[i+2][j+1]>0)
                {
                    dp[i+2][j+1]=max(dp[i+2][j+1],dp[i][j]+g[i+2][j+1]);
                    use[i+2][j+1]=1;
                }
            }
        }
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                if(use[i][j])
                    ans=max(ans,dp[i][j]);
            }
        printf("%d\n",ans);
    }
    return 0;
}
