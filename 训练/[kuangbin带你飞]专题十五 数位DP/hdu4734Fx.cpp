#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[20],dp[20][];
ll a[20];

int dfs(int pos,ll s,int lim)
{

}

int main()
{
    int _,n,i;
    a[0]=1;
    for(i=1;i<=10;i++)
        a[i]=2*a[i-1];
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        i=0;
        while(n)
        {
            num[++i]=n%10;
            n/10;
        }
        printf("%d\n",dfs(i,))
    }
    return 0;
}
