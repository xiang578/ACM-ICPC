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
const int mod=998244353;
const int N=100;
int w[N],n,m,K,q,f[N][N][N][4];
int g[N][N];

int ok(int x,int y)
{
    int t=abs(w[x]-w[y]);
    if(t<=K)
        return 1;
    else
        return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,u,v;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d%d",&n,&m,&K,&q);
        for(int i=1;i<=n;i++) scanf("%d",w+i);
        memset(g,0,sizeof(g));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            g[u][v]=1;
        }
        memset(f,0,sizeof(f));
        for(int i=n;i>=1;i--)
        {
            for(int j=n;j>=1;j--)
            {
                for(int k=n;k>=1;k--)
                {


                    for(int t=k+1;t<=n;t++)
                    {
                        if(g[k][t])
                            f[i][j][k][2]=(f[i][j][k][2]+f[i][j][t][0])%mod;
                    }

                    for(int t=j+1;t<=n;t++)
                    {
                        if(g[j][t])
                            f[i][j][k][1]=(f[i][j][k][1]+f[i][t][k][2])%mod;
                    }

                    if(ok(i,j)&&ok(j,k)&&ok(k,i)) f[i][j][k][0]=1;
                    else continue;
                    for(int t=i+1;t<=n;t++)
                    {
                        if(g[i][t])
                            f[i][j][k][0]=(f[i][j][k][0]+f[t][j][k][1])%mod;
                    }
                }
            }
        }
        for(int i=0;i<q;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            printf("%d\n",f[a][b][c][0]);
        }
    }
    return 0;
}

/*#include <cstdio>
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
const int mod=998244353;
const int N=100;
int w[N],n,m,K,q,f[N][N][N];
vector<int>g[N];

int ok(int x,int y)
{
    int t=abs(w[x]-w[y]);
    if(t<=K)
        return 1;
    else
        return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,u,v;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d%d",&n,&m,&K,&q);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",w+i);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            g[v].push_back(u);
        }
        memset(f,0,sizeof(f));
        for(int i=n;i>=1;i--)
        {
            for(int j=n;j>=1;j--)
            {
                for(int k=n;k>=1;k--)
                {
                    f[i][j][k]+=1;
                    if(!ok(i,j)||!ok(i,k)||!ok(j,k))
                    {
                        f[i][j][k]=0;
                        continue;
                    }
                    for(int a=0;a<g[i].size();a++)
                    {
                        for(int b=0;b<g[j].size();b++)
                        {
                            for(int c=0;c<g[k].size();c++)
                            {
                                f[g[i][a]][g[j][b]][g[k][c]]+=f[i][j][k];
                                f[g[i][a]][g[j][b]][g[k][c]]%=mod;
                            }
                        }
                    }

                }
            }
        }
        for(int i=0;i<q;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            printf("%d\n",f[a][b][c]);
        }
    }
    return 0;
}
*/
