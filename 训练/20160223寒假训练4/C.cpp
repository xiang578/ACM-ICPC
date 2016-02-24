/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
************************************************ */

#include <cstdio>
#include <cstring>
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
const int N=1<<16+1;

int vt[N],b[20];

int get(int x)
{
    int ret=0;
    while(x)
    {
        if(x%2==1) ret++;
        x/=2;
    }
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,k,i,j,t,p,cnt,ans,tmp;
    b[1]=1;
    for(i=2;i<=17;i++)
        b[i]=b[i-1]*2;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        cnt=1<<n;
        ans=0;
        memset(vt,0,sizeof(vt));
        for(i=1;i<=k;i++)
        {
            tmp=0;
            scanf("%d",&p);
            for(j=1;j<=p;j++)
            {
                scanf("%d",&t);
                tmp+=b[t];
            }
            vt[tmp]++;
        }
        for(i=1;i<=cnt;i++)
        {
            if(get(i)==m)
            {
                tmp=0;
                for(j=1;j<=i+1;j++)
                {
                    if((j|i)==i)
                        tmp+=vt[j];
                }
                if(tmp>ans) ans=tmp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
