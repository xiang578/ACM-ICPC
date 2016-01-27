/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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
const int N=2048;

int n,m,mp[120][120],g[120][120],ans[120][120];

int get(int x,int y)
{
    int ret=0;
    ret+=g[x-1][y]+g[x-2][y];
    ret+=g[x][y-1]+g[x-1][y-1]+g[x-2][y-1];
    ret+=g[x][y-2]+g[x-1][y-2]+g[x-2][y-2];
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,j,k,t,f,sum;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        memset(mp,0,sizeof(mp));
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                scanf("%d",&mp[i][j]);
        int cnt=1<<(n-2);
        sum=0;
        for(k=0; k<cnt; k++)
        {
            memset(g,0,sizeof(g));
            t=k;
            for(i=2; i<=n-1; i++)
            {
                g[i][1]=t%2;
                t/=2;
            }

            for(j=1; j<m; j++)
            {
                for(i=1; i<n; i++)
                {
                    g[i+1][j+1]=mp[i][j]-get(i+1,j+1);
                }
            }

            f=1;
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=m; j++)
                {
                    if(g[i][j]!=0&&g[i][j]!=1)
                    {
                        f=0;
                        break;
                    }
                    if(i==1&&g[i][j]!=0)
                    {
                        f=0;
                        break;
                    }
                    if(i==n&&g[i][j]!=0)
                    {
                        f=0;
                        break;
                    }
                    if(mp[i][j]!=get(i+1,j+1)+g[i+1][j+1])
                    {
                        f=0;
                        break;
                    }
                }
                if(f!=1) break;
            }

            if(f)
            {
                sum++;
                for(i=1; i<=n; i++)
                {
                    for(j=1; j<=m; j++)
                    {
                        ans[i][j]=g[i][j];
                    }
                }
            }
            if(sum>1) break;
        }

        if(sum>1)
            puts("Multiple");
        else if(sum==1)
        {
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=m; j++)
                {
                    if(j!=1) printf(" ");
                    printf("%d",ans[i][j]);
                }
                printf("\n");
            }
        }
        else
            puts("Impossible");

    }
    return 0;
}
