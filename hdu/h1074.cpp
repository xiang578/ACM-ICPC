#include<bits/stdc++.h>
using namespace std;
struct node
{
    int d,c;
    char s[100+5];
}a[20];
int n,b[20],use[20],ans;

void dfs(int now,int sum,int day,int t,int cnt)
{
    day+=a[now].c;
    if(day>a[now].d) sum+=day-a[now].d;
    use[cnt]=now;
    int i;
    if(cnt==n-1)
    {
        if(sum<ans)
        {
            for(i=0;i<n;i++)
                b[i]=use[i];
            ans=sum;
        }
        else if(sum==ans)
        {
            for(i=0;i<n;i++)
            {
                //printf("%d %d\n",b[i],use[i]);
                    if(use[i]>b[i])
                        break;
            }
            if(i==n)
            {
                for(i=0;i<n;i++)
                    {
                        b[i]=use[i];
                        //printf("%d\n",b[i]);
                    }
            }
        }
        return ;
    }
    if(sum>ans) return ;

    for(i=0;i<n;i++)
    {
        int k=1<<i;
        if(t&k) continue;
        dfs(i,sum,day,t|k,cnt+1);
    }
}

int main()
{
    int _,i;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s%d%d",a[i].s,&a[i].d,&a[i].c);
        ans=0xfffffff;
        for(i=0;i<n;i++)
            dfs(0,0,0,1<<i,0);
        printf("%d\n",ans);
        for(i=0;i<n;i++)
            printf("%s\n",a[b[i]].s);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int inf=0xfffffff;
struct node
{
    int pre;
    int day;
    int sum;
}dp[1<<16];

struct data
{
    int d,c;
    char s[120];
}a[20];

int main()
{
    int n,i,_,j,k,t;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s%d%d",a[i].s,&a[i].d,&a[i].c);
        }
        for(i=0;i<(1<<n);i++)
            dp[i].sum=inf;

        for(i=0;i<n;i++)
            for(j=0;!(j>>n);j++)
                for(k=0;k<n;k++)
                {
                    t=1<<k;
                    if(j&k)
                    {
                        if(dp[j].sum!=inf)
                        {
                            if(dp[j^t].day+a[k].c)
                        }
                        else
                        {
                            dp[j].day=dp[j^t].day+a[k].c;
                            if(dp[j].day-a[k].d>0)
                                dp[j].sum=dp[j].day-a[k].d;
                            else
                                dp[j].sum=0;
                            dp[j].pre=k;
                        }
                    }
                }
        t=(1<<n)-1;
        while(dp[t].pre)
        {
            printf("%s\n",a[dp[t].pre].s);
            t=dp[t].pre;
        }
    }
    return 0;
}
