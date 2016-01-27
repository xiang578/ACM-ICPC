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

int n,m,use[50][50],f;
char mp[50][50];
ll ans,pa,pb;

ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}

int get(char op,ll a,ll b,int c)
{
    if(op=='+')
    {
        pa=a+b*c;
        pb=b;
    }
    else if(op=='-')
    {
        pa=a-b*c;
        pb=b;
    }
    else if(op=='*')
    {
        pa=a*c;
        pb=b;
    }
    else if(op=='/')
    {
        if(c==0) return 0;
        pa=a;
        pb=b*c;
    }
    ll t=gcd(pa,pb);
    pa=pa/t;
    pb=pb/t;
    return 1;
}

void dfs(int x,int y,ll a,ll b)
{
    //printf("%lld %lld\n",a,b);
    if(a==b*ans||f==1) {f=1;return ;}
    use[x][y]=1;

    //up
    if(y-2>=0&&!use[x][y-2]&&mp[x][y-2]!='#')
    {
        //printf("%lld %lld\n",a,b);
        if(get(mp[x][y-1],a,b,mp[x][y-2]))
            dfs(x,y-2,pa,pb);
    }

    //down
    if(y+2<m&&!use[x][y+2]&&mp[x][y+2]!='#')
    {
        //printf("%lld %lld\n",a,b)
        if(get(mp[x][y+1],a,b,mp[x][y+2]))
            dfs(x,y+2,pa,pb);
    }

    //left
    if(x-2>=0&&!use[x-2][y]&&mp[x-2][y]!='#')
    {
        if(get(mp[x-1][y],a,b,mp[x-2][y]))
            dfs(x-2,y,pa,pb);
    }

    //right
    if(x+2<n&&!use[x+2][y]&&mp[x+2][y]!='#')
    {
        if(get(mp[x+1][y],a,b,mp[x+2][y]))
            dfs(x+2,y,pa,pb);
    }
    use[x][y]=0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,j;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%lld",&n,&m,&ans);
        for(i=0; i<n; i++)
            scanf("%s",mp[i]);

        for(i=0; i<n; i+=2)
            for(j=0; j<m; j+=2)
                if(mp[i][j]>='0'&&mp[i][j]<='9')
                    mp[i][j]=mp[i][j]-'0';
        f=0;
        for(i=0; i<n; i+=2)
            for(j=0; j<m; j+=2)
                if(0<=mp[i][j]&&mp[i][j]<=9&&!f)
                {
                    memset(use,0,sizeof(use));
                    //printf("%d\n",mp[i][j]);
                    dfs(i,j,mp[i][j],1);
                }
        if(f)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}
