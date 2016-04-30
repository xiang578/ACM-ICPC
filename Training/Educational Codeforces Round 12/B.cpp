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
    int ans=0,n,m,k,a[1024],t;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&t);
            //printf("%d\n",t);
            for(int p=1;p<=k;p++)
            {
                //printf("%d\n",a[p]);
                if(a[p]==t)
                {
                    //printf("%d %d\n",t,a[p]);
                    ans+=p;
                    a[p]=a[0];
                    a[1]=t;
                    break;
                }
                else
                {
                    swap(a[p],a[0]);
                }
            }

        }
    }
    printf("%d\n",ans);
    return 0;
}
