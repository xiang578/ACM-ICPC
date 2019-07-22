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
const int mod = 998244353;
long long ans = 0;
int a[N][11], b, c[N];
int cnt[N];
long long base[30];

int main()
{
    int n;
    base[0] = 1;
    base[1] = 1;
    for (int i=2; i<30; i++)
    {
        base[i] = base[i-1]*10 % mod;
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &b);
        int t = 0;
        if (b==0) 
        {
            t = 1;
            a[i][0] = 0;
        }
        while(b>0)
        {
            a[i][t] = b%10;
            b/=10;
            t++;
        }
        cnt[t] += 1;
        c[i] = t;
    }
    ans = 0;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<c[i]; j++)
        {
            //a[i][j]
            for (int k=1; k<=10; k++)
            {
                if (cnt[k] == 0) continue;
                if (k < j + 1) 
                {
                    int p = k + j + 1;
                    ans += (base[p] * 2 * cnt[k] * a[i][j]) % mod;
                    ans %= mod;
                    // cout<<a[i][j]<<" "<<cnt[k]<<" "<<k<<" "<<p<<endl;
                }
                else
                {
                    ans += (base[2*j + 2] * cnt[k] * a[i][j]) % mod;
                    ans %= mod;
                    ans += (base[2*j + 1] * cnt[k] * a[i][j]) % mod;
                    ans %= mod;
                    // cout<<a[i][j]<<" "<<cnt[k]<<" "<<k<<" "<<2*j+2<<" "<<2*j+1<<endl;
                }
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
