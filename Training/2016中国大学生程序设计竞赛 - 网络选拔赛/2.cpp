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

int a[MAXN][MAXN];//�������
int x[MAXN];//�⼯
bool free_x[MAXN];//����Ƿ��ǲ�ȷ���ı�Ԫ

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
    return a/gcd(a,b)*b;//�ȳ���˷����
}

// ��˹��Ԫ���ⷽ����(Gauss-Jordan elimination).(-2��ʾ�и������⣬���������⣬
//-1��ʾ�޽⣬0��ʾΨһ�⣬����0��ʾ����⣬���������ɱ�Ԫ�ĸ���)
//��equ�����̣�var����Ԫ�������������Ϊequ,�ֱ�Ϊ0��equ-1,����Ϊvar+1,�ֱ�Ϊ0��var.
int Gauss(int m,int n)
{
    int i = 0, j = 0, k, r, u;
    while(i < m && j < n)   // ��ǰ���ڴ����i�����̣���j������
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
            // ��Ԫ���i�еĵ�һ����0���ǵ�j�У��ҵ�u>i�еĵ�j�о�Ϊ0
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
