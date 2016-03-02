//ans当成int类型了
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
__int64 f[100][100];
int b[100];


__int64 get(__int64 x)
{
    int cnt=1,i,j,k;
    __int64 ans=0;
    while(x>0)
    {
        b[cnt]=x%10;
        x/=10;
        cnt++;
    }
    b[cnt]=0;
    for(i=cnt-1; i>=1; i--)
    {
        for(j=0; j<b[i]; j++)
        {
            if(j==9&&b[i+1]==4) continue;
            ans+=f[i][j];
        }
        if(b[i+1]==4&&b[i]==9) break;
    }
    return ans;
}

int main()
{
    int _,i,j,k;
    ll n;
    f[0][0]=1;
    for(i=1; i<=19; i++)
    {
        for(j=0; j<=9; j++)
        {
            for(k=0; k<=9; k++)
            {
                if(j==4&&k==9) continue;
                f[i][j]+=f[i-1][k];
            }
        }
    }
    scanf("%d",&_);
    while(_--)
    {
        cin>>n;
        cout<<n+1-get(n+1)<<endl;
    }
    return 0;
}
