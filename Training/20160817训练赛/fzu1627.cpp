#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int M=10000;

int N,m;
struct Matrix
{
    int mp[105][105];
    Matrix()
    {
        memset(mp,0,sizeof(mp));
    }
};

Matrix Mul(Matrix a,Matrix b)
{
    int i,j,k;
    Matrix c;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
        {
            c.mp[i][j]=0;
            for(k=0; k<N; k++)
            {
                c.mp[i][j]=(c.mp[i][j]+a.mp[i][k]*b.mp[k][j])%M;
            }
        }
    return c;
}

Matrix Pow(Matrix a,int n)
{
    Matrix c;
    for(int i=0; i<N; i++)
        c.mp[i][i]=1;
    while(n)
    {
        if(n&1) c=Mul(c,a);
        a=Mul(a,a);
        n/=2;
    }
    return c;
}

int main()
{
    int i,j,u,v,k,_;
    Matrix t;
    while(~scanf("%d%d%d",&N,&m,&k))
    {
        if(N==0&&m==0) break;
        for(i=0; i<N; i++)
            for(j=0; j<N; j++)
                t.mp[i][j]=0;

        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            t.mp[u][v]=1;
        }
        Matrix ans=t;
        ans=Pow(t,k);
        printf("%d\n",ans.mp[0][N-1]%M);
    }
    return 0;
}
