#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[15];
int dp[15][3];
//dp[i][k]
//i:数位
//k:3种状态，0-没有3\8，1-有3，2-有8

//pos为当前处理的数位（权重表示法，也就是剩下pos+1位待填数）
//have-状态;
//lim-后面的数是否可以任意填，1-不可以，0-可以
int dfs(int pos,int have,int lim)
{
    //printf("%d\n",pos);
    int n,i,ans=0,have_x;
    if(pos<=0&&have!=0) return 1;
    if(pos==0) return 0;
    //if(pos<0) return 0;
    //已经搜索过了
    if(!lim&&dp[pos][have]!=-1)
        return dp[pos][have];

    //判断本位枚举的范围
    n=lim?num[pos]:9;
    for(i=0; i<=n; i++)
    {
        have_x=have;
        if(have==0&&i==3)
            have_x=1;
        if(have==0&&i==8)
            have_x=2;
        if(have==1&&i==8)
            continue;
        if(have==2&&i==3)
            continue;
        ans+=dfs(pos-1,have_x,lim&&i==n);
    }

    //dp[pos][mod][have]要保存的是pos之后可以任意填的结果
    //存在dfs(...,1)和dfs(...,0)的区别，如果lim=1时，记录dp可能会导致错误
    //所以每一次dfs(...,1)都要重新计算
    if(!lim)
        dp[pos][have]=ans;
    return ans;
}

int main()
{
    int n,i,_,l,r,a1,a2;
    memset(dp,0xff,sizeof(dp));
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&l,&r);
        if(l==1) a1=0;
        else
        {
            n=l-1;
            memset(num,0,sizeof(num));
            i=0;
            while(n)
            {
                num[++i]=n%10;
                n/=10;
            }
            a1=dfs(i,0,1);
        }

        n=r;
        memset(num,0,sizeof(num));
        i=0;
        while(n)
        {
            num[++i]=n%10;
            n/=10;
        }
        a2=dfs(i,0,1);
        printf("%d\n",a2-a1);
    }
    return 0;
}
