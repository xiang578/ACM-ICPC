#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<iostream>
using namespace std;
using namespace std;
typedef long long ll;
const ll mod=1000000007;
int n;
ll m;
struct Matrix
{
    ll mp[20][20];
    Matrix()
    {
        memset(mp,0,sizeof(mp));
    }
};

Matrix mul(Matrix a,Matrix b)
{
    int i,j,k;
    Matrix c;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            c.mp[i][j]=0;
            for(k=0; k<n; k++)
            {
                c.mp[i][j]=(c.mp[i][j]+a.mp[i][k]*b.mp[k][j]%mod)%mod;
            }
        }
    }
    return c;

}

Matrix mypow(Matrix t,ll x)
{
    Matrix c;
    for(int i=0; i<n; i++)
    c.mp[i][i]=1;
    while(x)
    {
        if(x&1)
            c=mul(c,t);
        t=mul(t,t);
        x>>=1;
    }
    return c;

}
long long a[1024],b[1024],c[1024];

int main()
{
    int t;
    long long k;
    n=20;
    scanf("%d %lld",&t,&k);
    for(int i=0;i<t;i++)
    {
       scanf("%lld%lld%lld",a+i,b+i,c+i);
    }
    Matrix A;
    A.mp[0][0]=1;
    for(int p=0;p<t;p++)
    {
        Matrix B;
        for(int i=0;i<=c[p];i++)
        {
            if(i==0)
            {
                B.mp[0][0]=B.mp[1][0]=1;
            }
            else 
                //if(i<=c[p])
            {
                B.mp[i-1][i]=B.mp[i][i]=B.mp[i+1][i]=1;
            }
        }
        //if(a[p]==k) continue;
        //A =mul(A,B);
        //if(min(k,b[p])-a[p]-1<=0) continue;
        if(p) 
        for(int i=min(c[p-1],c[p])+1;i<n;i++) 
            A.mp[0][i]=0; 
        B=mypow(B,min(k,b[p])-a[p]);
        A=mul(A,B);
    }
    printf("%lld\n",A.mp[0][0]);
    return 0;
}
