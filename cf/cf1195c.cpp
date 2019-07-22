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
const int N = 123456;
long long dp[N][3];

int main()
{
    int n;
    int a[N][2];
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d", &a[i][0]);
    for (int i=1; i<=n; i++)
        scanf("%d", &a[i][1]);
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i=1; i<=n; i++)
    {
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        dp[i][1] = max(dp[i-1][0] + a[i][0], dp[i-1][2] + a[i][0]);
        dp[i][2] = max(dp[i-1][0] + a[i][1], dp[i-1][1] + a[i][1]);
    }
    long long ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
    printf("%lld\n", ans);
    return 0;
}
