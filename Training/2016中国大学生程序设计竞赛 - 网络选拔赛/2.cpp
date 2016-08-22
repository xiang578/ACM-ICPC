#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN=400+9;
const int inf=2e9+9;

int a[MAXN][MAXN];//增广矩阵
int x[MAXN];//解集
bool free_x[MAXN];//标记是否是不确定的变元

inline int gcd(int a,int b)
{
    int t;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
inline int lcm(int a,int b)
{
    return a/gcd(a,b)*b;//先除后乘防溢出
}

// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，
//-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
//有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
int Gauss(int m,int n)
{
    int i = 0, j = 0, k, r, u;
    while(i < m && j < n)   // 当前正在处理第i个方程，第j个变量
    {
        r = i;
        for(k = i; k < m; k++)
            if(a[k][j])
            {
                r = k;
                break;
            }
        if(a[r][j])
        {
            if(r != i) for(k = 0; k <= n; k++) swap(a[r][k], a[i][k]);
            // 消元后第i行的第一个非0列是第j列，且第u>i行的第j列均为0
            for(u = i+1; u < m; u++) if(a[u][j])
                    for(k = i; k <= n; k++) a[u][k] ^= a[i][k];
            i++;
        }
        j++;
    }
    return n-i;
}

const ll mod=1000000007;
ll prime[MAXN];
int loca;

int init();
ll quickpow(ll di,ll zhi);

int main()
{
    init();
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
        {
            ll tmp;
            scanf("%lld",&tmp);
            for(int j=0; j<loca; j++)
            {
                if(tmp<prime[j]) break;
                if(tmp%prime[j]!=0) continue;
                while(tmp%prime[j]==0)
                {
                    tmp/=prime[j];
                    a[j][i]=!a[j][i];
                }
            }
        }
        int go=Gauss(loca,n);
        ll ans=quickpow(2,go);
        ans-=1;
        printf("Case #%d:\n",cas++);
        printf("%lld\n",(ans%mod+mod)%mod);
    }
    return 0;
}

ll quickpow(ll di,ll zhi)
{
    ll ans=1;
    ll tmp=di;
    while(zhi)
    {
        if(zhi&1)
            ans*=tmp;
        ans%=mod;
        tmp*=tmp;
        tmp%=mod;
        zhi>>=1;
    }
    return ans;
}



int init()
{
    loca=0;
    prime[loca++]=2;
    for(int i=3; i<=2000; i++)
    {
        int flag=1;
        for(int j=2; j*j<=i; j++)
        {
            if(i%j==0)
            {
                flag=-1;
                break;
            }
        }
        if(flag==1)
            prime[loca++]=(ll)i;
    }
    return 0;
}
