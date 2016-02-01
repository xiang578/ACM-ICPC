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


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k,g[100][100],a[100],use[100],ans[100],i,j,n;
    while(~scanf("%d",&n))
    {
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                scanf("%d",&g[i][j]);
        memset(use,0,sizeof(use));
        memset(ans,0,sizeof(ans));
        for(i=1; i<=n; i++)
        {
            memset(a,0,sizeof(a));
            for(j=1; j<=n; j++)
            {
                k=g[i][j];
                if(!k) continue;
                a[k]++;
                if(a[k]==2)
                {
                    ans[i]=k;
                    use[k]=1;
                    break;
                }
            }
        }

        int f=0;
        for(i=1; i<=n; i++)
        {
            if(!ans[i])
            {
                for(j=1; j<=n; j++)
                    if(!use[j])
                    {
                        ans[i]=j;
                        use[j]=1;
                        break;
                    }
            }
        }

        for(i=1; i<=n; i++)
        {
            if(f) printf(" ");
            else f++;
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
