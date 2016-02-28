#include<bits/stdc++.h>
using namespace std;
const int N=1<<21;
struct node
{
    int ati,def,hp,exp;
} dp[N],e[1024],a,t;

int main()
{
    int a1,a2,a3,i,j,n,up;
    char s[1024];
    while(~scanf("%d%d%d%d%d%d",&a.ati,&a.def,&a.hp,&a1,&a2,&a3))
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%s%d%d%d%d",s,&e[i].ati,&e[i].def,&e[i].hp,&e[i].exp);
        up=1<<n;
        for(i=0; i<up; i++)
            dp[i].hp=0;
        dp[0].ati=a.ati;
        dp[0].def=a.def;
        dp[0].hp=a.hp;
        dp[0].exp=0;
        for(i=0; i<up; i++)
        {
            for(j=0; j<n; j++)
            {
                if(!(i&(1<<j))&&dp[i].hp)
                {
                    t.ati=dp[i].ati;
                    t.def=dp[i].def;
                    t.hp=dp[i].hp;
                    t.exp=dp[i].exp;
                    int m1=max(1,t.ati-e[j].def);
                    int m2=max(1,e[j].ati-t.def);
                    int t1=(e[j].hp+m1-1)/m1;//几次打死敌人
                    int t2=(t.hp+m2-1)/m2;//几次被打死
                    if(t2<t1) continue;
                    t.exp+=e[j].exp;
                    t.hp-=(t1-1)*m2;
                    if(t.exp>=100)
                    {
                        t.exp-=100;
                        t.ati+=a1;
                        t.def+=a2;
                        t.hp+=a3;
                    }
                    if(t.hp>=dp[i|(1<<j)].hp)
                    {
                        dp[i|(1<<j)].ati=t.ati;
                        dp[i|(1<<j)].def=t.def;
                        dp[i|(1<<j)].hp=t.hp;
                        dp[i|(1<<j)].exp=t.exp;
                    }
                }
            }
        }
        if(dp[up-1].hp) printf("%d\n",dp[up-1].hp);
        else puts("Poor LvBu,his period was gone.");
    }
    return 0;
}
