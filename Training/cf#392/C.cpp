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
const int N=2048;
const int M=1e6+10;
ll mp[200][200];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n,m,k,x,y,mx,mi,ans;
    while(cin>>n>>m>>k>>x>>y)
    {
        memset(mp,0,sizeof(mp));
        if(n==1)
        {
            ll sum=m;
            ll t=k/sum;
            ll w=k%sum;
            for(int i=1; i<=m; i++)
            {
                mp[1][i]=t;
                if(i<=w) mp[1][i]++;
            }
        }
        else
        {
            ll sum=(n-1)*m;
            ll t,w;
            if(k>=sum+m)
            {   k-=m;
                t=k/sum;
                w=k%sum;
            }
            else t=0,w=k;

            for(int i=2; i<n; i++)
                for(int j=1; j<=m; j++)
                    mp[i][j]=t;
            //"printf("%lld %lld\n",t,mp[x][y]);

            ll a,b;
            if(t!=0)
            {
                b=(t+1)/2;
                a=t+1-b;
            }
            else {a=b=0;}
            for(int i=1; i<=m; i++)
            {
                mp[1][i]=a;
                mp[n][i]=b;
            }
            //printf("%lld %lld\n",t,mp[x][y]);
            if(t%2==0)
            {
                ll cnt=0;
                int st;
                if(t==0) st=1;
                else st=2;
                for(int i=st; i<=n; i++)
                {
                    //printf("%lld %lld\n",cnt,w);
                    if(cnt>=w) break;
                    for(int j=1; j<=m; j++)
                    {
                        if(cnt>=w) break;
                        cnt++;
//printf("%lld %d %d\n",cnt,i,j);
                        mp[i][j]++;

                    }
                }
            }
            else
            {
                ll cnt=0;
                for(int i=n-1; i>=1; i--)
                {
                    if(cnt>=w) break;
                    for(int j=1; j<=m; j++)
                    {
                        if(cnt>=w) break;
                        cnt++;
                        mp[i][j]++;

                    }
                }
            }
            //printf("%lld %lld\n",t,mp[x][y]);
        }
        mx=mi=mp[1][1];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                mx=max(mx,mp[i][j]);
                mi=min(mi,mp[i][j]);
            }
        cout<<mx<<" "<<mi<<" "<<mp[x][y]<<endl;
    }
    return 0;
}
