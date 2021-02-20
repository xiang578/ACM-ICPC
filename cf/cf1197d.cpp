/* ***********************************************
Author        :xiang578
Email         :i@xiang578.com
Created Time  :Wed May 23 16:41:29 2018
File Name     :cf978c.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
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

using namespace std;

typedef long long ll;
const long long inf = 1e18;
ll a[312345],s[312345][11];
int f[312345][11];
int n, k, m;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n>>m>>k;
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int j=1; j<=m; j++)
        s[0][j] = -inf;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            s[i][j] = -inf;
            if (j==1){
                s[i][j] = a[i] - k;
                s[i][j] = max(s[i][j], s[i-1][m] + a[i] - k);
            }
            else
                s[i][j] = s[i-1][j-1] + a[i];
            ans = max(ans, s[i][j]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
